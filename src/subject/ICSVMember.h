#ifndef CSVMEMBER_H
#define CSVMEMBER_H

#include <string>

class ICSVMember{
public:
    virtual std::string phoneToCsvString(char, char) = 0;
    virtual void CsvStringToMe(std::string*, size_t) = 0;
    virtual char isExist() = 0;
};

#endif