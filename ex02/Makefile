# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 02:06:10 by vpoka             #+#    #+#              #
#    Updated: 2025/10/02 11:13:38 by vpoka            ###   ########.fr        #
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
	@ echo -e "$(YELLOW)$(NAME): Compiling...$(RST)"
	@ mkdir -p $(BUILD)

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME): $(BUILD) $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)
	@ echo -e "$(GREEN)$(NAME) built successfully!$(RST)"

run: all
	@ echo -e "$(CYAN)Starting $(NAME)...$(RST)"
	@ ./$(NAME)

clean:
	@ rm -rf $(BUILD)
	@ echo -e "$(RED)deleted BUILD files$(RST)"

fclean: clean
	@ rm -rf $(NAME)
	@ echo -e "$(RED)deleted PROGRAM file$(RST)"

re: fclean all

.PHONY: all clean fclean re run