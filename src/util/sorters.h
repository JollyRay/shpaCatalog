#ifndef SORTER_H
#define SORTER_H

#include "../subject/phone.h"

std::string chooseSorterMassege = "1 - model, 2 - brand, 3 - price, 4 - screen, 5 data, 6 -sim\n-->";

bool compareAlf(std::string first, std::string second) {
    size_t len = first.length() < second.length() ? first.length() : second.length();
    for (int letterNumber = 0; letterNumber < len; letterNumber++){
        if (first[letterNumber] != second[letterNumber]){
            return first[letterNumber] < second[letterNumber];
        }
    }
    return first.length() < second.length();
}

bool compareSim(Phone first, Phone second){
    return (first.getSim() < second.getSim());
}

bool compareDate(Phone first, Phone second){
    if (first.getYear() != second.getYear()){
        return first.getYear() > second.getYear();
    }
    return first.getMonth() > second.getMonth();
}

bool compareScreenSize(Phone first, Phone second){
    return (first.getScreenSize() < second.getScreenSize());
}

bool comparePrice(Phone first, Phone second){
    return (first.getPrice() < second.getPrice());
}

bool compareBrand(Phone first, Phone second){
    return compareAlf(first.getBrand(), second.getBrand());
}

bool compareModel(Phone first, Phone second){
    return compareAlf(first.getModel(), second.getModel());
}


#endif