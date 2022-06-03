CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -Wshadow -Wno-shadow
NAME = DiamondTrap
SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp DiamondTrap.cpp
OBJ = $(SRC:.cpp=.o)

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