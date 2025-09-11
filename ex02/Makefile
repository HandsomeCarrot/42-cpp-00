# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 02:06:10 by vpoka             #+#    #+#              #
#    Updated: 2025/09/11 17:36:07 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MP -MD

INC = -Iinclude

SRC = src
SRCS =	$(addprefix $(SRC)/, \
		Account.cpp \
		tests.cpp)

BUILD = build
OBJS = $(SRCS:$(SRC)/%.cpp=$(BUILD)/%.o)

#-----COLORS-----#

RST = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m

#-----RULES-----#

all: $(NAME)

$(BUILD):
	@ echo "$(YELLOW)$(NAME): Compiling...$(RST)"
	@ mkdir -p $(BUILD)

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME): $(BUILD) $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)$(NAME) built successfully!$(RST)"

run: all
	@ echo "$(CYAN)Starting $(NAME)...$(RST)"
	@ ./$(NAME)

clean:
	@ rm -rf $(BUILD)
	@ echo "$(RED)deleted BUILD files$(RST)"

fclean: clean
	@ rm -rf $(NAME)
	@ echo "$(RED)deleted PROGRAM file$(RST)"

re: fclean all

.PHONY: all clean fclean re run