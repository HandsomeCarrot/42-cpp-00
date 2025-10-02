# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 20:40:46 by vpoka             #+#    #+#              #
#    Updated: 2025/10/02 20:33:10 by vpoka            ###   ########.fr        #
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

$(NAME): $(BUILD) $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@ printf "$(GREEN)$(NAME) built successfully!$(RST)\n"

clean:
	@ rm -rf $(BUILD)
	@ printf "$(RED)$(NAME): deleted BUILD files$(RST)\n"

fclean: clean
	@ rm -f $(NAME)
	@ printf "$(RED)$(NAME): deleted PROGRAM file$(RST)\n"

re: fclean all

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

run: all
	@ printf "$(CYAN)Starting $(NAME)...$(RST)\n"
	@ ./$(NAME)

.PHONY: clean fclean re run