# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 20:45:39 by proberto          #+#    #+#              #
#    Updated: 2023/04/15 14:32:14 by proberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_HEADER = ./
NAME = sed
SRC =  main.cpp FileReader.cpp FileWriter.cpp String.cpp
OBJS_DIR = ./obj
OBJS = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f

# tests
FILE = poem
TEST_FILE = tests.sh
S1 = falta
S2 = alegria
GREEN = "\001\033[1;32m\002"
RESET = "\001\033[0m\002"
CAT = && cat $(FILE).replace
TEXT = "Não viva para que a sua presença seja notada, mas para que a sua \
falta seja sentida."

TEST1 = 'echo -e $(GREEN)"Test 1: two arguments"$(RESET)\n./$(NAME) $(FILE) $(S1)\n'
TEST2 = 'echo -e $(GREEN)"Test 2: four arguments"$(RESET)\n./$(NAME) $(FILE) $(S1) $(S2) $(S2)\n'
TEST3 = 'echo -e $(GREEN)"Test 3: invalid file"$(RESET)\n./$(NAME) zoom $(S1) $(S2)\n'
TEST4 = 'echo -e $(GREEN)"Test 4: empty strings"$(RESET)\n./$(NAME) $(FILE) "" "" $(CAT)\n'
TEST5 = 'echo -e $(GREEN)"Test 5: from(sua) to(tua)"$(RESET)\n./$(NAME) $(FILE) "sua" "tua" $(CAT)\n'
TEST6 = 'echo -e $(GREEN)"Test 6: from(Não viva) to(viva)"$(RESET)\n./$(NAME) $(FILE) "Não viva" "viva" $(CAT)\n'
TEST7 = 'echo -e $(GREEN)"Test 7: from(a) to(A)"$(RESET)\n./$(NAME) $(FILE) "a" "A" $(CAT)\n'
TEST8 = 'echo -e $(GREEN)"Test 8: from(a) to(b)"$(RESET)\n./$(NAME) $(FILE) "a" "b" $(CAT)\n'

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
	@echo $(TEXT) > $(FILE)
	@echo $(TEST1) > $(TEST_FILE)
	@echo $(TEST2) >> $(TEST_FILE)
	@echo $(TEST3) >> $(TEST_FILE)
	@echo $(TEST4) >> $(TEST_FILE)
	@echo $(TEST5) >> $(TEST_FILE)
	@echo $(TEST6) >> $(TEST_FILE)
	@echo $(TEST7) >> $(TEST_FILE)
	@echo $(TEST8) >> $(TEST_FILE)
	@bash $(TEST_FILE)
	@$(RM) $(TEST_FILE) $(FILE) $(FILE).replace

.PHONY: all clean fclean re test
