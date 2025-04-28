/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:05:08 by malanglo          #+#    #+#             */
/*   Updated: 2025/01/17 17:05:09 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cctype>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <cstdlib>

class  RPN {

    private:
        std::stack<std::string> _elem;

    public:
        RPN();
        ~RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& other);

        void fillStack(std::string input);
        void printStack();
        int calculate();
};

int acceptableChar(std::string input);
int acceptableDigit(std::string input);

#endif
