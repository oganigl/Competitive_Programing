#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
int  main(int argc, const char** argv) {
    std::string weather;
    std::string names[4]={" Adrian"," Barbara", " Carmen", " Dario"};
    std::string friends_to_walk;
    int temperature;
    std::cin>>weather;
    std::cin>>temperature;
    if(weather=="Soleado" && temperature>=20){
        friends_to_walk+=names[0];
    }
    if(weather=="Soleado" || temperature>15){
        friends_to_walk+=names[1];
    }
    if(weather=="Soleado" || weather=="Nublado"){
        friends_to_walk+=names[2];
    }
    if(weather!="Tormenta"){
        friends_to_walk+=names[3];
    }
    std::cout<<"Vienen a pasear:"<<friends_to_walk;
    return 0;
}