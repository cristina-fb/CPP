CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.phony: fclean clean re
