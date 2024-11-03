# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 16:50:17 by malanglo          #+#    #+#              #
#    Updated: 2024/10/29 09:53:25 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bank

CC = c++

FLAGS = -WALL -WEXTRA -WERROR -std=c++98

SRCS = 	tests.cpp\
		Account.cpp\

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
