#include <iostream>
#include "Contact.class.hpp"
#include "Phonebook.class.hpp"

void output_interface(void)
{
    std::cout << std::endl;
    std::cout << "//************************************//" << std::endl;
    std::cout << "//                                    //" << std::endl;
    std::cout << "//        MY AWESOME PHONEBOOK        //" << std::endl;
    std::cout << "//                                    //" << std::endl;
    std::cout << "//************************************//" << std::endl << std::endl;
}

int main(void)
{
    Phonebook my_phonebook;
    std::string option;
    std::string index;

    output_interface();
    std::cout << std::endl << "* Please write your operation (ADD, SEARCH, EXIT): ";
    while (std::getline(std::cin, option))
    {
        if (option == "ADD")
            my_phonebook.add_contact();
        else if (option == "SEARCH")
        {
            my_phonebook.show_list();
            std::cout << "-Enter your index choice: ";
            std::getline(std::cin, index);
            my_phonebook.show_info(index);
        }
        else if (option == "EXIT")
            break;
        else
            std::cout << "ERROR! Operation not found :(" << std::endl;
        std::cout << std::endl << "* Please write your operation (ADD, SEARCH, EXIT): ";
    }
    return (0);
}