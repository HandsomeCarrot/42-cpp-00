# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 15:12:48 by vpoka             #+#    #+#              #
#    Updated: 2025/09/10 20:26:00 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----PROGRAM-NAME-----#

NAME = megaphone

#-----COMPILATION-----#

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MD -MP

#-----FILES-----#

SRC = src
SRCS =	$(addprefix $(SRC)/, megaphone.cpp)

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

$(NAME): $(BUILD) $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)$(NAME) built successfully!$(RST)"

clean:
	@ rm -rf $(BUILD)
	@ echo "$(RED)$(NAME): deleted OBJECT files$(RST)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$(RED)$(NAME): deleted PROGRAM file$(RST)"

re: fclean all

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean fclean re
