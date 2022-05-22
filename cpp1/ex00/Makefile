CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
NAME = zombie
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
HEADER = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.phony: fclean clean re