CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
NAME = Materia
SRC = main.cpp Materia.cpp
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