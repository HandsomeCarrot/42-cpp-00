# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 20:40:46 by vpoka             #+#    #+#              #
#    Updated: 2025/09/11 17:32:11 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98 -MD -MP

INCLUDE = -Iinclude

SRC = src
SRCS =	$(addprefix $(SRC)/, \
		Contact.cpp \
		PhoneBook.cpp \
		main.cpp)

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
	@ $(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)$(NAME) built successfully!$(RST)"

clean:
	@ rm -rf $(BUILD)
	@ echo "$(RED)$(NAME): deleted BUILD files$(RST)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$(RED)$(NAME): deleted PROGRAM file$(RST)"

re: fclean all

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

run: all
	@ echo "$(CYAN)Starting $(NAME)...$(RST)"
	@ ./$(NAME)

.PHONY: clean fclean re run