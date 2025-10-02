# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 20:40:46 by vpoka             #+#    #+#              #
#    Updated: 2025/10/02 11:13:38 by vpoka            ###   ########.fr        #
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
	@ echo -e "$(YELLOW)$(NAME): Compiling...$(RST)"
	@ mkdir -p $(BUILD)

$(NAME): $(BUILD) $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@ echo -e "$(GREEN)$(NAME) built successfully!$(RST)"

clean:
	@ rm -rf $(BUILD)
	@ echo -e "$(RED)$(NAME): deleted BUILD files$(RST)"

fclean: clean
	@ rm -f $(NAME)
	@ echo -e "$(RED)$(NAME): deleted PROGRAM file$(RST)"

re: fclean all

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

run: all
	@ echo -e "$(CYAN)Starting $(NAME)...$(RST)"
	@ ./$(NAME)

.PHONY: clean fclean re run