#include "Contact.class.hpp"

Contact::Contact(void)
{
};

Contact::~Contact(void)
{
};

void Contact::new_contact(void)
{
    bool flag = false;

	std::cout << "Enter contact name: ";
    std::getline(std::cin, this->_name);
    std::cout << "Enter contact last name: ";
    std::getline(std::cin, this->_last_name);
    std::cout << "Enter contact nickname: ";
    std::getline(std::cin, this->_nickname);
    std::cout << "Enter contact darkest secret: ";
    std::getline(std::cin, this->_dark_secret);
    std::cout << "Enter contact phone: ";
    while (!flag)
    {
        std::getline(std::cin, this->_phone);
        if ((int)this->_phone.length() == 0)
        {
            std::cout << "Error! Enter numeric phone: ";
        }
        for (int i = 0; i < (int)this->_phone.length(); i++)
        {
            if (this->_phone[i] < '0' || this->_phone[i] > '9')
            {
                std::cout << "Error! Enter numeric phone: ";
                break;
            }
            if (i == (int)this->_phone.length() - 1)
                flag = true;
        }
    }
};

std::string Contact::get_name(void)
{
    return(this->_name);
};

std::string Contact::get_last_name(void)
{
    return(this->_last_name);
};

std::string Contact::get_nickname(void)
{
    return(this->_nickname);
};

std::string Contact::get_phone(void)
{
    return(this->_phone);
};

std::string Contact::get_secret(void)
{
    return(this->_dark_secret);
};