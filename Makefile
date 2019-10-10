# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/06 15:16:06 by gsmith            #+#    #+#              #
#    Updated: 2019/10/10 14:29:17 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
.SILENT: 
endif

NAME = avm

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra

DIR_SRC = src
DIR_BUILD = build
DIR_DEP = depend
DIR_INC = include

FILES_SRC = \
	avm.cpp
FILES_BUILD = $(FILES_SRC:.cpp=.o)
FILES_DEP = $(FILES_SRC:.cpp=.d)

SRC = $(addprefix $(DIR_SRC)/, $(FILES_SRC))
BUILD = $(addprefix $(DIR_BUILD)/, $(FILES_BUILD))
DEP = $(addprefix $(DIR_DEP)/, $(FILES_DEP))
INC = -I $(DIR_INC)

# Build all and rebuild

.PHONY: all
all: $(NAME)

.PHONY: re
re:
	rm -f $(BUILD)
	rm -df $(DIR_BUILD) || True
	rm -f $(NAME)
	@Make all

# Binary and pre-comp building

$(NAME): $(BUILD)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.cpp $(DIR_BUILD)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $< 

# Build and Depend directories

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(DIR_DEP):
	mkdir -p $(DIR_DEP)

# Depend files building

$(DIR_DEP)/%.d: $(DIR_SRC)/%.cpp $(DIR_DEP)
	$(CXX) $(CXXFLAGS) $(INC) -MT $(@:$(DIR_DEP)/%.d=$(DIR_BUILD)/%.o) -MM $< \
		| sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' > $@

# Files cleaning

.PHONY: clean
clean:
	rm -f $(BUILD)
	rm -df $(DIR_BUILD) 2>/dev/null || True
	rm -f $(DEP)
	rm -df $(DIR_DEP) 2>/dev/null || True

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

# include depend files

-include $(DEP)