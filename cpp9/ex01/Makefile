# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 17:04:17 by malanglo          #+#    #+#              #
#    Updated: 2025/01/17 17:04:18 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RPN

CXX := c++

CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRCS :=		main.cpp\
					RPN.cpp\

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
