#include "comandWorker.h"
#include "../util/sorters.h"

ComandWorker::ComandWorker(std::string *userPath,std::string *userMessage,std::string *phonePath,std::string *phoneMessage){
    this->phons = new Dataset<Phone>(phonePath, phoneMessage);
    users = new Dataset<User>(userPath, userMessage);

    this->mapping[comandType::addUser] = comandType::addUserNumber;
    this->mapping[comandType::removeUser] = comandType::removeUserNumber;
    this->mapping[comandType::addPhone] = comandType::addPhoneNumber;
    this->mapping[comandType::removePhone] = comandType::removePhoneNumber;
    this->mapping[comandType::show] = comandType::showNumber;
    this->mapping[comandType::sort] = comandType::sortNumber;
    this->mapping[comandType::find] = comandType::findNumber;
    this->mapping[comandType::exit] = comandType::exitNumber;
    this->mapping[comandType::showUser] = comandType::showUserNumber;
}

ComandWorker::~ComandWorker(){
    users->save();
    phons->save();
}

void ComandWorker::logining(){
    std::string login, password;
    while(1){
        std::cout << "Login: ";
        std::cin >> login;
        std::cout << "Password: ";
        std::cin >> password;
        this->self = users->find(new User(login, password));
        if (this->self){
            return;
        }
        std::cout << "Uncorrect login or password" << std::endl;
    }
}

void ComandWorker::execute(){
    while(1){
        std::cout << "-->";
        std::string command; 
        std::cin >> command;
        switch (mapping[trim(command)]){
            case comandType::addUserNumber: this->addUser(); break;
            case comandType::removeUserNumber: this->removeUser(); break;
            case comandType::addPhoneNumber: this->addPhone(); break;
            case comandType::removePhoneNumber: this->removePhone(); break;
            case comandType::showNumber: this->show(); break;
            case comandType::showUserNumber: this->showUser(); break;
            case comandType::findNumber: this->find(); break;
            case comandType::sortNumber: this->sort(); break;
            case comandType::exitNumber: return;
            default: std::cout << "uncorrect command" << std::endl; break;
        }
    }
}

void ComandWorker::init(){
    this->logining();
    this->execute();
}

void ComandWorker::addUser(){
    if (!this->self->getRoly()){
        std::cout << errMessage << std::endl;
        return;
    }
    std::string login, password;
    int roly;
    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Password: ";
    std::cin >> password;
    while (1){
        std::cout << "Roly: ";
        if (std::cin >> roly) {
            auto newUser = new User(login, password, roly);
            if (!users->find(newUser)){
                users->add(newUser);
                return;
            } else {
                std::cout << "User exist" << std::endl;
                return;
            }
        } else if (std::cin.bad()) {
            std::cout << "Uncorrect data" << std::endl;
        }
    }
}

void ComandWorker::removeUser(){
    if (!this->self->getRoly()){
        std::cout << errMessage << std::endl;
        return;
    }
    while(1){
        int id;
        std::cout << "id: ";
        if (std::cin >> id) {
            users->remove(id);
            return;
        } else {
            std::cout << "Uncorrect id" << std::endl;
        }
    }
}

void ComandWorker::addPhone(){
    if (!this->self->getRoly()){
        std::cout << errMessage << std::endl;
        return;
    }
    std::string model, brand;
    float price, screenSize;
    int month, year, sim2;
    std::cout << "brand: ";
    std::cin >> brand;
    std::cout << "model: ";
    std::cin >> model;
    while(1){
        if (std::cin >> price){
            break;
        } else {
            std::cout << "Uncorrect price" << std::endl;
        }
    }
    while(1){
        if (std::cin >> screenSize){
            break;
        } else {
            std::cout << "Uncorrect screen" << std::endl;
        }
    }
    while(1){
        if (std::cin >> month){
            break;
        } else {
            std::cout << "Uncorrect month" << std::endl;
        }
    }
    while(1){
        if (std::cin >> year){
            break;
        } else {
            std::cout << "Uncorrect year" << std::endl;
        }
    }
    while(1){
        if (std::cin >> sim2){
            phons->add(new Phone(brand, model, price, screenSize, month, year, sim2));
        } else {
            std::cout << "Uncorrect year" << std::endl;
        }
    }
}

void ComandWorker::removePhone(){
    if (!this->self->getRoly()){
        std::cout << errMessage << std::endl;
        return;
    }
    while(1){
        int id;
        std::cout << "id: ";
        if (std::cin >> id) {
            phons->remove(id);
            return;
        } else if (std::cin.bad()) {
            std::cout << "Uncorrect id" << std::endl;
        }
    }
}

int selectType(){
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

void ComandWorker::sort(){
    switch (selectType()){
    case comandType::sortBrandNumber:
        phons->sort(&compareBrand);
        return;
    case comandType::sortModelNumber:
        phons->sort(&compareModel);
        return;
    case comandType::sortPriceNumber:
        phons->sort(&comparePrice);
        return;
    case comandType::sortScreenNumber:
        phons->sort(&compareScreenSize);
        return;
    case comandType::sortDateNumber:
        phons->sort(&compareDate);
        return;
    case comandType::sortSimNumber:
        phons->sort(&compareSim);
        return;
    default:
        std::cout << "Uncorrect sorter" << std::endl;
        break;
    }
}

void ComandWorker::show(){
    auto data = phons->getData();
    auto ptr = data.begin();
    while(ptr != data.end()){
        std::cout << (*ptr)->toString();
        ptr++;
    }
}

void ComandWorker::showUser(){
    if (!this->self->getRoly()){
        std::cout << errMessage << std::endl;
        return;
    }
    auto data = users->getData();
    auto ptr = data.begin();
    while(ptr != data.end()){
        std::cout << (*ptr)->toString();
        ptr++;
    }
}

void ComandWorker::find(){
    int columnNumber = selectType();
    int counter = 0;
    std::string keyWord;
    std::cout << "Key Word: ";
    std::cin >> keyWord;
    keyWord = trim(keyWord);

    auto data = phons->getData();
    auto ptr = data.begin();
    while(ptr != data.end()){
        switch (columnNumber){
        case comandType::sortBrandNumber:
            if ((*ptr)->getBrand().find(keyWord) != -1){
                std::cout << (*ptr)->toString();
                counter++;
            };
            break;
        case comandType::sortModelNumber:
            if ((*ptr)->getModel().find(keyWord) != -1){
                std::cout << (*ptr)->toString();
                counter++;
            };
            break;
        case comandType::sortPriceNumber:
            try{
                if (abs((*ptr)->getPrice() - std::stof(keyWord)) < 0.01){
                    std::cout << (*ptr)->toString();
                    counter++;
                }
            } catch(...) {
                return;
            }
            break;
        default:
            std::cout << "Uncorrect sorter" << std::endl;
            break;
        }
        ptr++;
    }
    std::cout << "Total " << counter << std::endl;
}