# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 18:10:17 by malanglo          #+#    #+#              #
#    Updated: 2024/11/08 12:20:59 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex02

CXX := c++

CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRCS :=		main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp\
			FragTrap.cpp\

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re