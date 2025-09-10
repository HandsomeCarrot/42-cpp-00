# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 20:40:46 by vpoka             #+#    #+#              #
#    Updated: 2025/09/10 19:49:22 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98

INCLUDE = -IContact.hpp -IPhoneBook.hpp

SRCS =	Contact.cpp \
		PhoneBook.cpp \
		main.cpp

OBJ_FOLDER = objs
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)

#-----COLORS-----#

RST = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m

#-----RULES-----#

all: $(NAME)

$(OBJ_FOLDER):
	@ echo "$(YELLOW)$(NAME): Compiling...$(RST)"
	@ mkdir -p $(OBJ_FOLDER)

$(NAME): $(OBJ_FOLDER) $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)$(NAME) built successfully!$(RST)"

clean:
	@ rm -rf $(OBJ_FOLDER)
	@ echo "$(RED)$(NAME): deleted OBJECT files$(RST)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$(RED)$(NAME): deleted PROGRAM file$(RST)"

re: fclean all

$(OBJ_FOLDER)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: re
	@ echo "$(CYAN)Starting $(NAME)...$(RST)"
	@ ./phonebook

.PHONY: clean fclean re run