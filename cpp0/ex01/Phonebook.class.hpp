#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include <iostream>
# include "Contact.class.hpp"

class Phonebook
{
    public:
        Contact list[8];

        Phonebook(void);
        ~Phonebook(void);
        void add_contact(void);
        void show_list(void);
        void show_info(std::string index);
    
    private:
        int _index;
        int _n_contacts;
};
#endif