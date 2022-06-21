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

void ComandWorker::execute(std::string *userMessage, std::string *managerMessage){
    std::cout << *userMessage << std::endl;
    if (self->getRoly()){
        std::cout << *managerMessage << std::endl;
    }
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

void ComandWorker::init(std::string *userMessage, std::string *managerMessage){
    this->logining();
    this->execute(userMessage, managerMessage);
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
        std::cout << "Price: ";
        if (std::cin >> price){
            break;
        } else {
            std::cout << "Uncorrect price" << std::endl;
        }
    }
    while(1){
        std::cout << "Screen: ";
        if (std::cin >> screenSize){
            break;
        } else {
            std::cout << "Uncorrect screen" << std::endl;
        }
    }
    while(1){
        std::cout << "month: ";
        if (std::cin >> month){
            break;
        } else {
            std::cout << "Uncorrect month" << std::endl;
        }
    }
    while(1){
        std::cout << "Year: ";
        if (std::cin >> year){
            break;
        } else {
            std::cout << "Uncorrect year" << std::endl;
        }
    }
    while(1){
        std::cout << "Sim: ";
        if (std::cin >> sim2){
            phons->add(new Phone(brand, model, price, screenSize, month, year, sim2));
            return;
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

void ComandWorker::sort(){
    switch (selectType(chooseSorterMassege)){
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
    std::cin.ignore(1000,'\n');
    std::string modelPattern, brandPattern;
    float pricePattern, screenPattern;
    int yearPattern, monthPattern;
    int simPattern;

    modelPattern = collectString(modelRequast);
    brandPattern = collectString(brandRequast);
    pricePattern = collectFloat(priceRequast);
    screenPattern = collectFloat(screenSizeRequast);
    yearPattern = collectInt(yearRequast);
    monthPattern = collectInt(monthRequast);
    simPattern = collectInt(simRequast);

    int counter = 0;
    auto data = phons->getData();
    auto ptr = data.begin();

    while(ptr != data.end()){
        if (
            ( (*ptr)->getBrand().find(modelPattern) != -1 || trim(modelPattern).length() == 0) &&
            ( (*ptr)->getModel().find(brandPattern) != -1 || trim(brandPattern).length() == 0) &&
            ( abs((*ptr)->getPrice()-pricePattern) < 0.01 || pricePattern < 0) &&
            ( abs((*ptr)->getScreenSize()-screenPattern) < 0.01 || screenPattern < 0) &&
            ( (*ptr)->getMonth() == monthPattern || monthPattern < 0) &&
            ( (*ptr)->getYear() == yearPattern || yearPattern < 0) &&
            ( (*ptr)->getSim() == simPattern || simPattern < 0)
        ){
            std::cout << (*ptr)->toString();
            counter++;
        }
        ptr++;
    }
    std::cout << "Total " << counter << std::endl;
}