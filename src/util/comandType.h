#ifndef COMANDTYPE_H
#define COMANDTYPE_H

#include <string>

namespace comandType{
    const std::string addUser = "addUser";
    const char addUserNumber = 8;
    const std::string removeUser = "removeUser";
    const char removeUserNumber = 1;
    const std::string addPhone = "add";
    const char addPhoneNumber = 2;
    const std::string removePhone = "remove";
    const char removePhoneNumber = 3;
    const std::string show = "show";
    const char showNumber = 4;
    const std::string showUser = "showUser";
    const char showUserNumber = 9;
    const std::string find = "find";
    const char findNumber = 5;
    const std::string sort = "sort";
    const char sortNumber = 6;
    const std::string exit = "exit";
    const char exitNumber = 7;

    const int sortBrandNumber = 1;
    const int sortModelNumber = 2;
    const int sortPriceNumber = 3;
    const int sortScreenNumber = 4;
    const int sortDateNumber = 5;
    const int sortSimNumber = 6;
}

#endif