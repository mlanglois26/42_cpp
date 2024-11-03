/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:34:05 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/01 11:41:43 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

int	main(int argc, char **argv) {
	
	if (argc <= 1) {
		
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << std::endl;
	}
	else {
		
		std::string s;
		for (int i = 1; argv[i] != 0; i++) {
			
			for (int x = 0; x < std::strlen(argv[i]); x++) {
				
				s += std::toupper(argv[i][x]);
			}
			if (argv[i + 1] != 0) {
				
				s += " ";
			}
		}
		std::cout << s << std::endl;
	}
	return (0);
}
