#ifndef MYCONST_H
#define MYCONST_H

#include <string>

std::string mobileResource = "resources/dataset.csv";
std::string startModelMessage = "brand_name,model_name,best_price,screen_size,release_date,sim2\nALCATEL,1 1/8GB Bluish Black (5033D-2JALUAA),1690.000000,5.000000,10-2020,0\n";
std::string userResource = "resources/user.csv";
std::string startUserMessage = "login,password,roly\nroot,root,1\n";

std::string helloMessage = "Hello, please enter your login and password";

std::string commanHelpMessage = "Сommon сommand List:\n\tshow - show all phons\n\tfind - looking for phon on param\n\tsort - sort phon's list\n\texit - exit\n";
std::string managerHelpMessage = "Manager сommand List:\n\tadd - add new phone\n\tremove - add new phone\n\taddUser - add new user\n\tremoveUser - add new user\n\tshowUser - show all user\n";

#endif