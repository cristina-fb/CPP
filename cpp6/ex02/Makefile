# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 16:33:18 by crisfern          #+#    #+#              #
#    Updated: 2022/12/20 10:58:03 by crisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
NAME =
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.phony: fclean clean re