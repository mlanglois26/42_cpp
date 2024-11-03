# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:43:40 by malanglo          #+#    #+#              #
#    Updated: 2024/10/30 13:14:19 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = repertoire

CC = c++

FLAGS = -WALL -WEXTRA -WERROR -std=c++98

SRCS = 	main.cpp\
		PhoneBook.cpp\
		Contact.cpp\
		Getters.cpp\
		Setters.cpp\
		ContactHelper.cpp\
		PhoneBookHelper.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):		${OBJS}
		$(CC) $(OBJS) $(FLAGS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
