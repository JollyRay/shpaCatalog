#ifndef COMANDREADER_H
#define COMANDREADER_H

#include <map> 
#include <cmath>
#include "../subject/user.h"
#include "../subject/phone.h"
#include "../dataProcessor/dataset.h"
#include "../util/comandType.h"

class ComandWorker
{
private:
    User *self;
    std::map <std::string, char> mapping;
    std::string errMessage = "Permission denied";

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
    void execute();
public:
    ComandWorker(std::string*, std::string*,std::string*, std::string*);
    ~ComandWorker();

    void init();
    
};

#endif