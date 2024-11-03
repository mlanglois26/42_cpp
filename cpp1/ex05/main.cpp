/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:02:13 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 12:42:30 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    
    Harl obj;

    const char* str[7] = {"I am tired", "I am happy", "error", "debug", "info", "warning", "aie aie aie"};

    for (int i = 0; i < 7; i++) {
        obj.complain(str[i]); 
    }

    obj.complain("I am hungry");    
    obj.complain("debug");    
    obj.complain("info");     
    obj.complain("warning");  
    obj.complain("something else");    
    obj.complain("error");
    obj.complain("I am tired");    
    obj.complain("info");     

    return (0);
}

