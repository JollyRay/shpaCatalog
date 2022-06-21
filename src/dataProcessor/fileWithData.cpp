#include "fileWithData.h"

FileWithData::FileWithData(std::string *path, std::string* startMessage){
    CSVfile.open(*path);
    FileWithData::path = path;
    if (!CSVfile.is_open()){
        CSVfile.close();
        std::ofstream outfile (*path);
        outfile << *startMessage;
        outfile.close();
        CSVfile.open(*path);
    }
    setlocale(LC_ALL, "RUS"); //WTF

    std::string lineWithHeader;
    getline(CSVfile, lineWithHeader, CSVlineEnd);
    CSVwidth = countCSVColumn(lineWithHeader);
    headers = extractHeaders(lineWithHeader);
    
}

FileWithData::~FileWithData(){
    CSVfile.close();
    delete path, headers;
}

size_t FileWithData::countCSVColumn(std::string line){
    size_t count = 0;
    char isDot = -1; 
    for (char letter : line){
        if (letter == CSVslice){
            count++;
            isDot = -1;
        } else {
            isDot = 0;
        }
    }
    if (!isDot){
        count++;
    }
    return count;
}

std::string* FileWithData::extractHeaders(std::string headerLine){
    if (!CSVwidth){
        return nullptr;
    }
    std::string* headerName = new std::string[CSVwidth];
    int* slicePtr = new int(0);

    for (int columnNumber = 0; columnNumber < CSVwidth; columnNumber++){
        *slicePtr = headerLine.find(CSVslice);
        if (*slicePtr == -1){
            headerName[columnNumber] = headerLine;
        } else{
            headerName[columnNumber] = headerLine.substr(0, *slicePtr);
            headerLine = headerLine.substr(*slicePtr+1);
        }
    }

    delete slicePtr;
    return headerName;
}

std::string* FileWithData::getHeaders(){
    return headers;
}

void FileWithData::getNextRow(std::string* dataLine){
    if (!CSVfile.is_open()){
        CSVfile.open(*path);
        getline(CSVfile, *dataLine, CSVlineEnd);
    }
    getline(CSVfile, *dataLine, CSVlineEnd);
}

void FileWithData::getNextMember(ICSVMember* nextMember){
    std::string discriptionPhone;
    getNextRow(&discriptionPhone);
    if (trim(discriptionPhone).length() == 0){
        return;
    }

    std::string* params = extractHeaders(discriptionPhone);
    if (!params){
        return;
    }

    nextMember->CsvStringToMe(params, CSVwidth);
}

char FileWithData::hasNext(){
    return !CSVfile.eof();
}

void FileWithData::saveData(ICSVMember** data, size_t dataQuantity){
    if (CSVfile.is_open()){
        CSVfile.close();
        std::ofstream file(*path);
        for (int columnNumber = 0; columnNumber < CSVwidth; columnNumber++){
            file << headers[columnNumber];
            if (columnNumber != CSVwidth-1){
                file << CSVslice;
            } else {
                file << CSVlineEnd;
            }
        }
        while(dataQuantity--){
            file << (*data)->phoneToCsvString(CSVslice, CSVlineEnd);
            data++;
        }
    }
}