# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 10:21:40 by malanglo          #+#    #+#              #
#    Updated: 2024/11/12 09:18:58 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = 	main.cpp\
		AMateria.cpp\
		Cure.cpp\
		Ice.cpp\
		MateriaSource.cpp\
		Character.cpp\
	
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $^ -o $@

clean:
		rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

