# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 16:33:18 by crisfern          #+#    #+#              #
#    Updated: 2023/01/03 14:53:04 by crisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
NAME = serialize
SRC = main.cpp Data.cpp functions.cpp
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.d))

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@
-include $(DEP)

clean:
	rm -rf $(DEP) $(OBJ) $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.phony: fclean clean re