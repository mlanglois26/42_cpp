# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 08:42:42 by malanglo          #+#    #+#              #
#    Updated: 2025/01/23 08:42:43 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe

CXX := c++

CXXFLAGS += -Wall -Wextra -Werror -std=c++98 -g3

SRCS :=		main.cpp\

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


