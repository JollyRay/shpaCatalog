#ifndef USER_H
#define USER_H

#include "ICSVMember.h"

class User : public ICSVMember
{
private:
    std::string login;
    std::string password;
    char roly;
    char exist = 0;

    const static size_t paramSize = 3;
public:
    User();
    User(std::string,std::string,char);
    User(std::string,std::string);
    ~User();

    std::string phoneToCsvString(char, char);
    void CsvStringToMe(std::string*, size_t);
    char isExist();

    std::string getLogin();
    std::string getPassword();
    char getRoly();
    std::string toString();

    char operator == (User Ref) const {
        return this->login == Ref.getLogin() && this->password == Ref.getPassword();
    }
};

#endif