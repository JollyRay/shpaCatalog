#include "user.h"
#include <iostream>

User::User(){};

User::User(std::string login, std::string password, char roly){
    this->login = login;
    this->password = password;
    this->roly = roly;

    this->exist = 1;
}

User::User(std::string login, std::string password){
    this->login = login;
    this->password = password;
}

User::~User(){};

std::string User::phoneToCsvString(char CSVslice, char CSVlineEnd){
    std::string discription;
    
    discription.append(this->login);
    discription += CSVslice;

    discription.append(this->password);
    discription += CSVslice;

    discription.append(std::to_string(this->roly));
    discription += CSVlineEnd;

    return discription;
}

void User::CsvStringToMe(std::string* params, size_t size){
    if (size != paramSize){
        return;
    }

    this->login = params[0];
    this->password = params[1];
    this->roly = std::stoi(params[2]);
    this->exist = 1;
}

char User::isExist(){
    return this->exist;
}

std::string User::getLogin(){
    return this->login;
}

std::string User::getPassword(){
    return this->password;
}

char User::getRoly(){
    return this->roly;
}

std::string User::toString(){
    return this->phoneToCsvString(' ', '\n');
}