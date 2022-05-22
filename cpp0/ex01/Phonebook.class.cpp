#include "Phonebook.class.hpp"

std::string resize_name(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	else if (str.length() < 10)
	{
		str.resize(10, ' ');
	}
	return(str);
}

Phonebook::Phonebook(void)
{
	this->_index = 0;
	this->_n_contacts = 0;
};

Phonebook::~Phonebook(void)
{
};

void Phonebook::add_contact(void)
{
	list[this->_index].new_contact();
	if (this->_n_contacts < 8)
		this->_n_contacts++;
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
};

void Phonebook::show_list(void)
{
	std::cout << std::endl << "|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
	for(int i = 0; i < this->_n_contacts; i++)
	{
		std::cout << "|" << i << "         |";
		std::cout << resize_name(list[i].get_name()) << "|";
		std::cout << resize_name(list[i].get_last_name()) << "|";
		std::cout << resize_name(list[i].get_nickname()) << "|" << std::endl;
	}
	std::cout << std::endl;
};

void Phonebook::show_info(std::string index)
{
	if (this->_n_contacts == 0)
	{
		std::cout << "Empty phonebook!" << std::endl;
	}
	else if (index.length() != 1)
	{
		std::cout << "Index not correct!" << std::endl;
	}
	else if ((index[0] < '0') || (index[0] >= '0' + this->_n_contacts))
	{
		std::cout << "Index not correct!" << std::endl;
	}
	else
	{
		std::cout << " NAME: " << list[index[0] - '0'].get_name() << std::endl;
		std::cout << " LAST_NAME: " << list[index[0] - '0'].get_last_name() << std::endl;
		std::cout << " NICKNAME: " << list[index[0] - '0'].get_nickname() << std::endl;
		std::cout << " PHONE: " << list[index[0] - '0'].get_phone() << std::endl;
		std::cout << " DARKEST SECRET: " << list[index[0] - '0'].get_secret() << std::endl;
	}
};