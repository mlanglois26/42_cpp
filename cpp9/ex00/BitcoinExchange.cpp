/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:38:51 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/17 12:38:53 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Canonic Form */

BitcoinExchange::BitcoinExchange() : _dbData(), _inputData() {};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
    this->_dbData = copy._dbData;
    this->_inputData = copy._inputData;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_dbData = other._dbData;
        this->_inputData = other._inputData;
    }
    return (*this);
};

/* Parsing */

int isValidYear(std::string year) {

    std::string res;

    for (size_t i = 0; i < year.length(); ++i) {

        if (std::isdigit(year[i]) != 0) {
            res += year[i];
        }
        else {
            return (INVALID_CHAR_YEAR);
        }
    }
    if (std::atoi(res.c_str()) < 2009 || std::atoi(res.c_str()) > 2022) {
        return (OUT_OF_RANGE_YEAR);
    }
    return (0);
}

int isValidMonths(std::string months) {

    std::string res;

    for (size_t i = 0; i < months.length(); ++i) {
        if (std::isdigit(months[i]) != 0) {
            res += months[i];
        }
        else {
            return (INVALID_CHAR_MONTHS);
        }
    }
    if (std::atoi(res.c_str()) < 1 || std::atoi(res.c_str()) > 12) {
        return (OUT_OF_RANGE_MONTHS);
    }
    return (0);
}

int isValidDay(std::string day) {

    std::string res;

    for (size_t i = 0; i < day.length(); ++i) {
        if (std::isdigit(day[i]) != 0) {
            res += day[i];
        }
        else {
            return (INVALID_CHAR_DAY);
        }
    }
    if (std::atoi(res.c_str()) < 1 || std::atoi(res.c_str()) > 31) {
        return (OUT_OF_RANGE_DAY);
    }
    return (0);
}

int isValidValue(std::string value) {

    if (value.empty())
        return (OUT_OF_RANGE_VALUE);

    bool hasDecimalPoint = false;
    std::string res;
    for (size_t i = 0; i < value.length(); ++i) {
        if (std::isdigit(value[i])) {
            res += value[i];
        }
        else if (value[i] == '.' && !hasDecimalPoint) {
            res += value[i];
            hasDecimalPoint = true;
        }
        else {
            return (INVALID_VALUE);
        }
    }
    float floatValue = std::atof(res.c_str());
    if (floatValue < 0 || floatValue > 1000) {
        return (OUT_OF_RANGE_VALUE);
    }
    return 0;
}

int isValidDateFormat(std::string line) {

    if (line.empty())
        return (EMPTY_LINE);

    if (line.length() < 14)
        return (FORMAT_ISSUE);

    std::string year = line.substr(0, 4);
    std::string month = line.substr(5, 2);
    std::string day = line.substr(8, 2);
    std::string value = line.substr(13);

    int yearError = isValidYear(year);
    if (yearError != 0)
        return (yearError);

    int monthError = isValidMonths(month);
    if (monthError != 0)
        return (monthError);

    int dayError = isValidDay(day);
    if (dayError != 0)
        return (dayError);

    if (line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
        return (INVALID_SEPARATOR);
    }

    int valueError = isValidValue(value);
    if (valueError != 0)
        return (valueError);

    return (0);
}

/* LOAD DATABASE */

void BitcoinExchange::loadDatabase(const std::string& fileName) {

    std::ifstream inFile(fileName.c_str());

    if (!inFile) {
        std::cerr << "Error: Cannot open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {

        std::istringstream iss(line);
        std::string date;
        float value;

        if (std::getline(iss, date, ',') && (iss >> value)) {
            _dbData[date] = value;

        }
    }
    inFile.close();
}

void BitcoinExchange::printDatabase() const {
    if (_dbData.empty()) {
        return;
    }

    for (std::map<std::string, float>::const_iterator it = _dbData.begin(); it != _dbData.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}

/* LOAD INPUT FILE */

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int year, int month) {
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

int finalCheck(std::string date) {

    std::string minDate = "2009-01-02";
    std::string maxDate = "2022-03-29";

    if (date < minDate || date > maxDate)
        return (OUT_OF_RANGE_DATE);

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    int maxDays = daysInMonth(year, month);
    if (day < 1 || day > maxDays) {
        return SPECIAL_DAY;
    }
    return (0);
}

void BitcoinExchange::loadInputFile(const std::string& fileName) {

    std::ifstream inFile(fileName.c_str());

    if (!inFile) {
        std::cerr << "Error: Cannot open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        try {
            std::string date;
            float value;

            int errorCode = isValidDateFormat(line);
            if (errorCode == 0) {
                date = line.substr(0, 10);
                value = std::atof(line.substr(13).c_str());
                int finalCheckError = finalCheck(date);
                if (finalCheckError != 0) {
                    throw BitcoinExchangeException(static_cast<ErrorCode>(finalCheckError));
                }
                else
                    _inputData.insert(std::make_pair(date, value));
            } else {
                throw BitcoinExchangeException(static_cast<ErrorCode>(errorCode));
            }
        }
        catch (const BitcoinExchangeException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    inFile.close();
}

void BitcoinExchange::printInputData() const {
    if (_inputData.empty()) {
        return;
    }

    for (std::map<std::string, float>::const_iterator it = _inputData.begin(); it != _inputData.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }
}

/* COMPARE BOTH FILES */

void BitcoinExchange::compareBothFiles() {

    for (std::map<std::string, float>::const_iterator it = _inputData.begin(); it != _inputData.end(); ++it) {
        const std::string& date = it->first;
        float inputValue = it->second;

        if (_dbData.find(date) != _dbData.end()) {
            printRes(date, inputValue, _dbData[date]);
        } else {

            std::map<std::string, float>::const_iterator previousIt = _dbData.lower_bound(date);

            if (previousIt != _dbData.begin()) {
                --previousIt;
                printRes(date, inputValue, previousIt->second);
            } else {
                std::cerr << "No previous date found in database.\n";
            }
        }
    }
}

void BitcoinExchange::printRes(const std::string& date, float inputValue, float dbValue) {
    std::cout << date << " => " << inputValue << " = " << dbValue * inputValue << std::endl;
}

/* Error Handling */

const char* BitcoinExchange::BitcoinExchangeException::what() const throw() {

    switch (_errorCode) {
        case INVALID_CHAR_YEAR:
            return "Invalid character in year";
        case OUT_OF_RANGE_YEAR:
            return "Year is out of range (2009-2022)";
        case INVALID_CHAR_MONTHS:
            return "Invalid character in month";
        case OUT_OF_RANGE_MONTHS:
            return "Month is out of range (01-12)";
        case INVALID_CHAR_DAY:
            return "Invalid character in day";
        case OUT_OF_RANGE_DAY:
            return "Day is out of range (01-31)";
        case INVALID_VALUE:
            return "Invalid character in value";
        case OUT_OF_RANGE_VALUE:
            return "Value is out of range";
        case INVALID_SEPARATOR:
            return "Invalid Separtor";
        case EMPTY_LINE:
            return "Line is empty";
        case FORMAT_ISSUE:
            return "Expected Format is: YYYY-MM-DD | value";
        case OUT_OF_RANGE_DATE:
            return "Date must be between 2009-01-02 and 2022-03-29";
        case SPECIAL_DAY:
            return "Please make sure there is a 31st in this months or that this is not a leap year";
        default:
            return "Unknown error";
    }
}
