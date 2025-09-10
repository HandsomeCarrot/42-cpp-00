# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 20:40:46 by vpoka             #+#    #+#              #
#    Updated: 2025/09/10 20:12:16 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98 -MD -MP

INCLUDE = -Iinclude

SRCS =	Contact.cpp \
		PhoneBook.cpp \
		main.cpp

COMPILATION = compilation
OBJS = $(SRCS:%.cpp=$(COMPILATION)/%.o)

#-----COLORS-----#

RST = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m

#-----RULES-----#

all: $(NAME)

$(COMPILATION):
	@ echo "$(YELLOW)$(NAME): Compiling...$(RST)"
	@ mkdir -p $(COMPILATION)

$(NAME): $(COMPILATION) $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)$(NAME) built successfully!$(RST)"

clean:
	@ rm -rf $(COMPILATION)
	@ echo "$(RED)$(NAME): deleted OBJECT files$(RST)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$(RED)$(NAME): deleted PROGRAM file$(RST)"

re: fclean all

$(COMPILATION)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	@ echo "$(CYAN)Starting $(NAME)...$(RST)"
	@ ./phonebook

.PHONY: clean fclean re run