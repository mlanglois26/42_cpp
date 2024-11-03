/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:37 by malanglo          #+#    #+#             */
/*   Updated: 2024/11/03 13:34:04 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replace(std::string &line, std::string &toSearch, std::string &toReplace) {

    std::string newLine;
    int start = 0;
    int foundPos = line.find(toSearch);

    while (foundPos != std::string::npos) {

        newLine += line.substr(start, foundPos - start);
        newLine += toReplace;
        start = foundPos + toSearch.length();
        foundPos = line.find(toSearch, start);
    }
    newLine += line.substr(start);
    return (newLine);
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        
        std::cout << "The program expects 3 arguments - no more no less." << std::endl;
    }
    else
    {
        std::string line; 
        std::ifstream in_file(argv[1]);
        if (in_file) {
            
            std::ofstream out_file("copy.txt");
            if (in_file && out_file) {
                
                std::string toSearch = argv[2];
                std::string toReplace = argv[3];
                while (getline(in_file, line)) {
                
                    out_file << replace(line, toSearch, toReplace) << "\n";
                }
            }
            out_file.close();
        }
        else {
            
            std::cout << "Error: Cannot read file" << std::endl;
        }
        in_file.close();
    }
    return (0);
}
