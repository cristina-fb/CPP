CXX = clang++
#CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
NAME = BSP
SRC = Fixed.cpp main.cpp bsp.cpp Point.cpp
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