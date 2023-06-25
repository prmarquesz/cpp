# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 20:45:39 by proberto          #+#    #+#              #
#    Updated: 2023/04/15 14:32:42 by proberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_HEADER = ./
NAME = harl
SRC =  main.cpp Harl.cpp
OBJS_DIR = ./obj
OBJS = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f

# tests
TEST_FILE = tests.sh
GREEN = "\001\033[1;32m\002"
RESET = "\001\033[0m\002"

TEST1 = 'echo -e $(GREEN)"Test 1: No argument"$(RESET)\n./$(NAME)\n'
TEST2 = 'echo -e $(GREEN)"Test 2: Two arguments"$(RESET)\n./$(NAME) ERROR INFO\n'
TEST3 = 'echo -e $(GREEN)"Test 3: Invalid argument"$(RESET)\n./$(NAME) ERRORS\n'
TEST4 = 'echo -e $(GREEN)"Test 4: Debug"$(RESET)\n./$(NAME) DEBUG\n'
TEST5 = 'echo -e $(GREEN)"Test 5: INFO"$(RESET)\n./$(NAME) INFO\n'
TEST6 = 'echo -e $(GREEN)"Test 6: WARNING"$(RESET)\n./$(NAME) WARNING\n'
TEST7 = 'echo -e $(GREEN)"Test 7: ERROR"$(RESET)\n./$(NAME) ERROR\n'

all:	$(NAME)

$(NAME):    $(addprefix $(OBJS_DIR)/, $(OBJS))
	@$(CC) -I$(PATH_HEADER) $(addprefix $(OBJS_DIR)/, $(OBJS)) -o $@

$(OBJS_DIR)/%.o:	%.cpp
	@mkdir -p $(OBJS_DIR)/
	@$(CC) -c $(CPPFLAGS) -I$(PATH_HEADER) $< -o $@

clean:		
	@$(RM) $(addprefix $(OBJS_DIR)/, $(OBJS))

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

test: all
	@echo $(TEST1) >  $(TEST_FILE)
	@echo $(TEST2) >> $(TEST_FILE)
	@echo $(TEST3) >> $(TEST_FILE)
	@echo $(TEST4) >> $(TEST_FILE)
	@echo $(TEST5) >> $(TEST_FILE)
	@echo $(TEST6) >> $(TEST_FILE)
	@echo $(TEST7) >> $(TEST_FILE)
	@bash $(TEST_FILE)
	@$(RM) $(TEST_FILE)

.PHONY: all clean fclean re test
