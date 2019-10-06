# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/06 15:16:06 by gsmith            #+#    #+#              #
#    Updated: 2019/10/06 17:04:30 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra

DIR_SRC = src
DIR_BUILD = build
DIR_DEP = dep
DIR_INC = include

FILES_SRC = \
	avm.cpp
FILES_BUILD = $(FILES_SRC:.cpp=.o)
FILES_DEP = $(FILES_SRC:.cpp=.dep)

SRC = $(addprefix $(DIR_SRC)/, $(FILES_SRC))
BUILD = $(addprefix $(DIR_BUILD)/, $(FILES_BUILD))
DEP = $(addprefix $(DIR_DEP)/, $(FILES_DEP))
INC = -I $(DIR_INC)

$(NAME): $(BUILD)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.cpp $(DIR_BUILD)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $< 

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(DIR_DEP)/%.dep: $(DIR_SRC)/%.cpp $(DIR_DEP)
	$(CXX) $(CXXFLAGS) $(INC) -MT $(@:$(DIR_DEP)/%.dep=$(DIR_BUILD)/%.o) -MM $< > $@

$(DIR_DEP):
	mkdir -p $(DIR_DEP)

-include $(DEP)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(BUILD)
	rm -df $(DIR_BUILD)
	rm -f $(DEP)
	rm -df $(DIR_DEP)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all