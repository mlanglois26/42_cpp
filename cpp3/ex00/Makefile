# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 15:36:21 by malanglo          #+#    #+#              #
#    Updated: 2024/11/08 10:19:41 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex00

CXX := c++

CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRCS :=		main.cpp\
			ClapTrap.cpp\

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
