#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include "trim.h"

std::string collectString(std::string message);

float collectFloat(std::string message);

int collectInt(std::string message);

int selectType(std::string chooseSorterMassege);

#endif