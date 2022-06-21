#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <fstream>
#include <vector>
#include "../subject/phone.h"
#include "fileWithData.h"

template <typename T>
class Dataset
{
private:
    std::vector<T*> members;
    FileWithData *file;
    size_t quantity = 0;
public:
    Dataset(std::string*, std::string*);
    ~Dataset();

    void add(T*);
    void remove(int);
    T* find(T*);
    void load();
    void save();
    void sort(bool (*pt2Func)(T,T));
    std::vector<T*> getData();
};

#include "dataset.tpp"

#endif