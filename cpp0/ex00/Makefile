CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
SRC = megaphone.cpp
NAME = megaphone

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean $(NAME)

.phony: clean re