#include "util.h"

std::string collectString(std::string message){
    std::string target;
    while(1){
        std::cout << message << std::endl;
        if (getline(std::cin, target, '\n')){
            return target;
        }
    }
}

float collectFloat(std::string message){
    float target;
    std::string pattern;
    while(1){
        std::cout << message << std::endl;
        getline(std::cin, pattern, '\n');
        pattern = trim(pattern);
        if (pattern.length() == 0){
            target = -1.0;
            return target;
        }
        try{
            target = std::stof(pattern);
            return target;
        } catch(...){
            std::cout << "Uncorrect data" << std::endl;
        }
    }
}

int collectInt(std::string message){
    int target;
    std::string pattern;
    while(1){
        std::cout << message << std::endl;
        getline(std::cin, pattern, '\n');
        pattern = trim(pattern);
        if (pattern.length() == 0){
            target = -1;
            return target;
        }
        try{
            target = std::stoi(pattern);
            return target;
        } catch(...){
            std::cout << "Uncorrect data" << std::endl;
        }
    }
}

int selectType(std::string chooseSorterMassege){
    int columnNumber;
    while(1){
        std::cout << chooseSorterMassege;
        if (std::cin >> columnNumber && columnNumber > 0 && columnNumber < 7){
            return columnNumber;
        } else {
            std::cout << "Uncorrect sorter" << std::endl;
        }
    }
}
