#include <string>
#include <iostream>
#include "phone.h"

Phone::Phone(){};

Phone::Phone(std::string brand, std::string model, float price, float screenSize, char month, int year, char sim2){
    this->brand = brand;
    this->model = model;
    this->price = price;
    this->screenSize = screenSize;
    this->month = month;
    this->year = year;
    this->sim2 = sim2;

    this->exist = 1;
}

Phone::~Phone(){};

std::string Phone::phoneToCsvString(char CSVslice, char CSVlineEnd){
    std::string discription;
    
    discription.append(this->brand);
    discription += CSVslice;

    discription.append(this->model);
    discription += CSVslice;

    discription.append(std::to_string(this->price));
    discription += CSVslice;

    discription.append(std::to_string(this->screenSize));
    discription += CSVslice;

    discription.append(std::to_string(this->month));
    discription.append(std::string(1, '-'));
    discription.append(std::to_string(this->year));
    discription += CSVslice;

    discription.append(std::to_string(this->sim2));
    discription += CSVlineEnd;

    return discription;
}

void Phone::CsvStringToMe(std::string* params, size_t size){
    if (size != paramSize){
        return;
    }
    this->brand = params[0];
    this->model = params[1];
    this->price = std::stof(params[2]);
    this->screenSize = std::stof(params[3]);
    int tildaPos = params[4].find('-');
    this->month = stoi(params[4].substr(0, tildaPos));
    this->year = stoi(params[4].substr(tildaPos+1));
    this->sim2 = static_cast<char>(std::stoi(params[5]));

    this->exist = 1;
}

char Phone::isExist(){
    return this->exist;
}

std::string Phone::getBrand(){
    return this->brand;
}

std::string Phone::getModel(){
    return this->model;
}

int Phone::getPrice(){
    return this->price;
}

std::string Phone::toString(){
    return this->phoneToCsvString('\t', '\n');
}


float Phone::getScreenSize(){
    return this->screenSize;
}

char Phone::getMonth(){
    return this->month;
}

int Phone::getYear(){
    return this->year;
}

char Phone::getSim(){
    return this->sim2;
}