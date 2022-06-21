#ifndef COMANDREADER_H
#define COMANDREADER_H

#include <map> 
#include <cmath>
#include "../subject/user.h"
#include "../subject/phone.h"
#include "../dataProcessor/dataset.h"
#include "../util/comandType.h"
#include "../util/util.h"

class ComandWorker
{
private:
    User *self;
    std::map <std::string, char> mapping;
    std::string errMessage = "Permission denied";
    
    std::string modelRequast = "Enter model (or just ENTER):";
    std::string brandRequast = "Enter brand (or just ENTER):";
    std::string priceRequast = "Enter price (or just ENTER):";
    std::string screenSizeRequast = "Enter screen size (or just ENTER):";
    std::string monthRequast = "Enter month (or just ENTER):";
    std::string yearRequast = "Enter year (or just ENTER):";
    std::string simRequast = "Enter sim (or just ENTER):";

    Dataset<User> *users;
    Dataset<Phone> *phons;

    void addUser();
    void removeUser();
    void addPhone();
    void removePhone();
    void sort();
    void show();
    void showUser();
    void find();

    void logining();
    void execute(std::string*, std::string*);
public:
    ComandWorker(std::string*, std::string*,std::string*, std::string*);
    ~ComandWorker();

    void init(std::string*, std::string*);
    
};

#endif