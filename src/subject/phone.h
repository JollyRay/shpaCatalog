#ifndef PHONE_H
#define PHONE_H

#include "ICSVMember.h"

class Phone : public ICSVMember
{
private:
    std::string brand;
    std::string model;
    float price;
    float screenSize;
    char month;
    int year;
    char sim2;
    char exist = 0;

    const static size_t paramSize = 6;
public:
    Phone();
    Phone(std::string,std::string,float,float,char,int,char);
    ~Phone();

    std::string getBrand();
    std::string getModel();
    int getPrice();
    float getScreenSize();
    char getMonth();
    int getYear();
    char getSim();
    std::string toString();

    std::string phoneToCsvString(char, char);
    void CsvStringToMe(std::string*, size_t);
    char isExist();
};

#endif