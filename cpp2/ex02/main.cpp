/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:25:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/08 09:51:53 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}

// int main( void ) {
    
//     Fixed a(10.5f);
//     Fixed b(10.5f);

//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "a + b = " << Fixed( a + b ) << std::endl;
//     std::cout << "a - b = " << Fixed( a - b ) << std::endl;
//     std::cout << "a * b = " << Fixed( a * b ) << std::endl;
//     std::cout << "a / b = " << Fixed( a / b ) << std::endl;

//     return 0;
// }

// int main(void) {

//     Fixed a(10);
//     Fixed b(10);
    
//     if (a > b)
//         std::cout << "a > b = OK" << std::endl;
//     else
//         std::cout << "a > b = NOP" << std::endl;

//     if (a >= b)
//         std::cout << "a >= b OK" << std::endl;
//     else
//         std::cout << "a >= b = NOP" << std::endl;

//     if (a < b)
//         std::cout << "a < b = OK" << std::endl;
//     else
//         std::cout << "a < b = NOP" << std::endl;

//     if (a <= b)
//         std::cout << "a <= b OK" << std::endl;
//     else
//         std::cout << "a <= b = NOP" << std::endl;

//     if (a == b)
//         std::cout << "a == b = OK" << std::endl;
//     else
//         std::cout << "a == b = NOP" << std::endl;

//     if (a != b)
//         std::cout << "a != b OK" << std::endl;
//     else
//         std::cout << "a != b = NOP" << std::endl;
    
//     return (0);
// }

// int main( void ) {
    
//     Fixed a(2);
    
//     std::cout << a << std::endl;

//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;

//     std::cout << --a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a-- << std::endl;
//     std::cout << a << std::endl;
    
//     return 0;
// }

// int main( void ) {
    
//     Fixed const a(15);
//     Fixed const b(20);

//     Fixed c(45);
//     Fixed d(10);
    
//     std::cout << "Max = " << Fixed::max( a, b ) << std::endl;
//     std::cout << "Min = " << Fixed::min( a, b ) << std::endl;
    
//     std::cout << "Max = " << Fixed::max( c, d ) << std::endl;
//     std::cout << "Min = " << Fixed::min( c, d ) << std::endl;
    
//     return 0;
// }

