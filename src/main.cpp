#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "dataProcessor/dataset.h"
#include "dataProcessor/fileWithData.h"
#include "subject/ICSVMember.h"
#include "subject/user.h"
#include "util/comandType.h"
#include "util/const.h"
#include "console/comandWorker.h"

using namespace std;

int main(){
    ComandWorker *container = new ComandWorker(&userResource, &startUserMessage, &mobileResource, &startModelMessage);
    container->init();
    delete container;

    return 0;
}