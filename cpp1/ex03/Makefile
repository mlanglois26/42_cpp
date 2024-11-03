# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 16:07:42 by malanglo          #+#    #+#              #
#    Updated: 2024/11/01 18:03:28 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CXX = c++

FLAGS = -WALL -WEXTRA -WERROR -std=c++98

SRCS = 	main.cpp\
		Weapon.cpp\
		HumanA.cpp\
		HumanB.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):		${OBJS}
		$(CXX) $(OBJS) $(FLAGS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
