# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:02:00 by malanglo          #+#    #+#              #
#    Updated: 2024/11/03 12:51:36 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HarlFilter

CXX = c++

FLAGS = -WALL -WEXTRA -WERROR -std=c++98

SRCS = 	main.cpp\
		Harl.cpp\
		
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
