#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <iostream>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        void new_contact(void);
        std::string get_name(void);
        std::string get_last_name(void);
        std::string get_nickname(void);
        std::string get_phone(void);
        std::string get_secret(void);
    
    private:
        std::string _name;
        std::string _last_name;
        std::string _nickname;
        std::string _dark_secret;
        std::string _phone;
};
#endif