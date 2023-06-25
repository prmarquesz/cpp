# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 20:45:39 by proberto          #+#    #+#              #
#    Updated: 2023/06/04 16:15:45 by proberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_HEADER = ./
NAME = btc
SRC =  main.cpp BitcoinExchange.cpp
OBJS_DIR = ./obj
OBJS = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f


all:	$(NAME)

$(NAME):    $(addprefix $(OBJS_DIR)/, $(OBJS))
	$(CC) $(addprefix $(OBJS_DIR)/, $(OBJS)) -o $@

$(OBJS_DIR)/%.o:	%.cpp
	mkdir -p $(OBJS_DIR)/
	$(CC) -c $(CPPFLAGS) -I$(PATH_HEADER)/ $< -o $@

clean:		
	$(RM) $(addprefix $(OBJS_DIR)/, $(OBJS))

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
