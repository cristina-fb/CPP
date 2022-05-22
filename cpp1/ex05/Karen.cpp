#include "Karen.hpp"

typedef void (Karen::*fpointers)(void);

Karen::Karen( void )
{
	std::cout << "Karen is ready to complain" << std::endl;
};

Karen::~Karen( void )
{
	std::cout << "Karen is going to sleep" << std::endl;
};

void Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
};

void Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
};

void Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
};

void Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
};

void Karen::complain( std::string level )
{
	std::string str[4] = {"debug", "info", "warning", "error"};
	fpointers fp[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	for(int i = 0; i < 4; i++)
	{
		if (str[i] == level)
		{
			(this->*fp[i])();
			return;
		}
	}
	std::cout << "You sent an incorrect level of complain!" << std::endl;
};
