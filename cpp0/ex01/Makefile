CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
NAME = myawesomephonebook
SRC = myawesomephonebook.cpp Contact.class.cpp Phonebook.class.cpp
HEADER = Contact.class.hpp Phonebook.class.hpp
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