# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 02:06:10 by vpoka             #+#    #+#              #
#    Updated: 2025/10/02 20:33:10 by vpoka            ###   ########.fr        #
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
DEPS = $(OBJS:.o=.d)

#-----COLORS-----#

RST = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m

#-----RULES-----#

-include $(DEPS)

all: $(NAME)

$(BUILD):
	@ printf "$(YELLOW)$(NAME): Compiling...$(RST)\n"
	@ mkdir -p $(BUILD)

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME): $(BUILD) $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)
	@ printf "$(GREEN)$(NAME) built successfully!$(RST)\n"

run: all
	@ printf "$(CYAN)Starting $(NAME)...$(RST)\n"
	@ ./$(NAME)

clean:
	@ rm -rf $(BUILD)
	@ printf "$(RED)deleted BUILD files$(RST)\n"

fclean: clean
	@ rm -rf $(NAME)
	@ printf "$(RED)deleted PROGRAM file$(RST)\n"

re: fclean all

.PHONY: all clean fclean re run