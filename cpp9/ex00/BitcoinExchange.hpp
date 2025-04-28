/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:38:45 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/17 12:38:46 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip> 
#include <iomanip> 
#include <exception>

enum ErrorCode {
    INVALID_CHAR_YEAR = 1,
    OUT_OF_RANGE_YEAR = 2,
    INVALID_CHAR_MONTHS = 3,
    OUT_OF_RANGE_MONTHS = 4,
    INVALID_CHAR_DAY = 5,
    OUT_OF_RANGE_DAY = 6,
    INVALID_VALUE = 7,
    OUT_OF_RANGE_VALUE = 8,
    INVALID_SEPARATOR = 9,
    EMPTY_LINE = 10,
    FORMAT_ISSUE = 11,
    OUT_OF_RANGE_DATE = 12,
    SPECIAL_DAY = 13,
};

class BitcoinExchange {

    private:
        std::map<std::string, float> _dbData;
        std::multimap<std::string, float> _inputData;
    
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void loadDatabase(const std::string& fileName);
        void loadInputFile(const std::string& fileName);
        void compareBothFiles();
        
        /* Print Helpers */

        void printDatabase() const;
        void printInputData() const;
        void printRes(const std::string& date, float inputValue, float dbValue);

    class BitcoinExchangeException : public std::exception {
        public:
            BitcoinExchangeException(ErrorCode code) : _errorCode(code) {}
            virtual const char* what() const throw();

        private:
            ErrorCode _errorCode;
        };
};

#endif
