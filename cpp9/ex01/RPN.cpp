/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:04:55 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/17 17:04:58 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* Canonic Form */

RPN::RPN() : _elem() {};

RPN::RPN(const RPN& copy) {
    this->_elem = copy._elem;
};

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_elem = other._elem;
    }
    return (*this);
};

RPN::~RPN() {};

/* Parsing */

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (1);
    return (0);
}

int acceptableChar(std::string input) {

    if (input.empty()) {
        std::cerr << "Error, empty input" << std::endl;
        return (1);
    }
    for (int i = 0; input[i] != '\0'; i++) {
        if (std::isdigit(input[i]) == 0 && isOperator(input[i]) == 0 && std::isspace(input[i]) == 0) {
            std::cerr << "Error, please provide only digits or '+', '-', '*' or '/'." << std::endl;
            return (1);
        }
    }
    return (0);
}

int acceptableDigit(std::string input) {
    for (int i = 0; input[i] != '\0'; i++) {

        if (input[i] == ' ')
            continue ;
        if (input[i + 1] != ' ' && input[i + 1] != '\0') {
            std::cerr << "Error, please make sure to provide only nb from 0 to 10 and that everything is separted by spaces." << std::endl;
            return (1);
        }
    }
    return (0);
}

void RPN::fillStack(std::string input) {

    std::istringstream iss(input);
    std::stack<std::string> tmpStack;
    std::string token;

    while (iss >> token) {
        tmpStack.push(token);
    }

    while (!tmpStack.empty()) {
        this->_elem.push(tmpStack.top());
        tmpStack.pop();
    }
}

void RPN::printStack() {
    std::stack<std::string> temp = this->_elem;
    while (!temp.empty()) {
        std::cout << temp.top() << std::endl;
        temp.pop();
    }
}

void printMyStack(std::stack<int> stack) {
    std::cout << "Current stack (top to bottom): ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

int RPN::calculate() {

    std::stack<int> resultStack;

    while (!_elem.empty()) {
        std::string token = _elem.top();
        _elem.pop();

        if (std::isdigit(token[0])) {
            resultStack.push(std::atoi(token.c_str()));
        }
        else if (isOperator(token[0]))
        {
            if (resultStack.size() < 2) {
                std::cerr << "Error, not enough numbers to perform operation." << std::endl;
                return (-1);
            }

            int elem2 = resultStack.top();
            resultStack.pop();
            int elem1 = resultStack.top();

            resultStack.pop();

            if (token == "+") {
                resultStack.push(elem1 + elem2);
            } else if (token == "-") {
                resultStack.push(elem1 - elem2);
            } else if (token == "*") {
                resultStack.push(elem1 * elem2);
            } else if (token == "/") {
                if (elem2 == 0) {
                    std::cerr << "Error, division by zero." << std::endl;
                    return (-1);
                }
                resultStack.push(elem1 / elem2);
            }
        }
        else {
            std::cerr << "Error, something went wrong..." << std::endl;
            return (-1);
        }
    }

    if (resultStack.size() != 1) {
        std::cerr << "Error, invalid RPN input." << std::endl;
        return (-1);
    }

    return resultStack.top();
}
