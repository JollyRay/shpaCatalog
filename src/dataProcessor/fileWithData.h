#ifndef FILEWORKER
#define FILEWORKER

#include <fstream>
#include <string>
#include <vector>
#include "../subject/ICSVMember.h"
#include "../util/trim.h"

class FileWithData
{
private:
    const static char CSVslice = ',';
    const static char CSVlineEnd = '\n';

    std::ifstream CSVfile;
    std::string* path;
    std::string* headers;
    size_t CSVwidth;

    size_t countCSVColumn(std::string);
    std::string* extractHeaders(std::string);
public:
    FileWithData(std::string*, std::string*);
    ~FileWithData();

    std::string* getHeaders();
    void getNextRow(std::string*);
    void getNextMember(ICSVMember*);
    char hasNext();
    void saveData(ICSVMember**, size_t);
};

#endif