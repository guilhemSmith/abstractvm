# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/06 15:16:06 by gsmith            #+#    #+#              #
#    Updated: 2019/10/10 17:10:56 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
.SILENT: 
endif

# Compiling macros

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

# progression variable

O = $(words $(BUILD))
I = 0
B = $(words $I)$(eval I := x $I)

D = $(words $(DEP))
J = 0
W = $(words $J)$(eval J := x $J)

# Color and output macros

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

S_N = [0;
S_B = [1;
S_D = [2;
S_I = [3;
S_L = [4;

NC = \033[0m

PREFIX = $(subst $(S_N),$(S_D),$(WHITE))[$(NAME)] - $(NC)

# Build all and rebuild

.PHONY: all
all: $(NAME)

.PHONY: re
re:
ifndef VERBOSE
	printf "\r$(PREFIX)$(RED)Cleaning object files...$(NC)"
endif
	rm -f $(BUILD)
	rm -df $(DIR_BUILD) || True
ifndef VERBOSE
	printf "\r$(PREFIX)$(PURPLE)Cleaning complete.            \n$(NC)"
endif
ifndef VERBOSE
	printf "$(PREFIX)$(RED)Deleting $(subst $(S_N),$(S_B),$(RED))$(NAME)$(RED) binary...$(NC)"
endif
	rm -f $(NAME)
ifndef VERBOSE
	printf "\r$(PREFIX)$(PURPLE)Binary $(subst $(S_N),$(S_B),$(PURPLE))$(NAME)$(PURPLE) deleted.          \n$(NC)"
endif
	@Make all

# Binary and object files building

$(NAME): $(BUILD)
ifndef VERBOSE
	printf "\r$(PREFIX)$(YELLOW)Compiling $(subst $(S_N),$(S_B),$(YELLOW))$(NAME)$(YELLOW) binary...$(NC)"
endif
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^
ifndef VERBOSE
	printf "\r$(PREFIX)$(BLUE)Binary $(subst $(S_N),$(S_B),$(BLUE))$(NAME)$(BLUE) ready.                   \n$(NC)"
endif

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.cpp $(DIR_BUILD)
ifndef VERBOSE
	printf "\r$(PREFIX)$(YELLOW)Compiling $@...$(NC)"
endif
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<
ifndef VERBOSE
  ifeq ($B,$O)
	printf "\r$(PREFIX)$(BLUE)Object files ready.                       \n$(NC)"
  endif
endif
 
$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(DIR_DEP):
	mkdir -p $(DIR_DEP)

# Depend files building

$(DIR_DEP)/%.d: $(DIR_SRC)/%.cpp $(DIR_DEP)
ifndef VERBOSE
	printf "\r$(PREFIX)$(YELLOW)Writing dependency $@...$(NC)"
endif
	$(CXX) $(CXXFLAGS) $(INC) -MT $(@:$(DIR_DEP)/%.d=$(DIR_BUILD)/%.o) -MM $< \
		| sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' > $@
ifndef VERBOSE
  ifeq ($D,$W)
	printf "\r$(PREFIX)$(CYAN)Dependencies files updated.                       \n$(NC)"
  endif
endif

# Files cleaning

.PHONY: clean
clean:
ifndef VERBOSE
	printf "\r$(PREFIX)$(RED)Cleaning object files...$(NC)"
endif
	rm -f $(BUILD)
	rm -df $(DIR_BUILD) 2>/dev/null || True
ifndef VERBOSE
	printf "\r$(PREFIX)$(RED)Cleaning dependencies files...$(NC)"
endif
	rm -f $(DEP)
	rm -df $(DIR_DEP) 2>/dev/null || True
ifndef VERBOSE
	printf "\r$(PREFIX)$(PURPLE)Cleaning complete.            \n$(NC)"
endif

.PHONY: fclean
fclean: clean
ifndef VERBOSE
	printf "\r$(PREFIX)$(subst $(S_N),$(S_B),$(RED))Deleting $(NAME)$(RED) binary...$(NC)"
endif
	rm -f $(NAME)
ifndef VERBOSE
	printf "\r$(PREFIX)$(PURPLE)Binary $(subst $(S_N),$(S_B),$(PURPLE))$(NAME)$(PURPLE) deleted.          \n$(NC)"
endif

# include depend files

-include $(DEP)