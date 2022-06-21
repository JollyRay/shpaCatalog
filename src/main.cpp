#include <iostream>
#include "util/const.h"
#include "console/comandWorker.h"

using namespace std;

int main(){
    std::cout << helloMessage << std::endl;
    ComandWorker *container = new ComandWorker(&userResource, &startUserMessage, &mobileResource, &startModelMessage);
    container->init(&commanHelpMessage, &managerHelpMessage);
    delete container;

    return 0;
}