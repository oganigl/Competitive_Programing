#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string.h>
int  main(int argc, const char** argv) {
    int number,players,subs;
    std::cin>>number>>players;
    int guess[players];
    float punctuation[players];
    int i=0;
    int j=players;
    while(players--){
        std::cin>>guess[i];
        subs=guess[i]-number;
        subs=abs(subs);
        if(subs==0){
            punctuation[i]=1;
        }
        else if(subs<=5){
            punctuation[i]=0.5;
        }
        else if(subs<=10){
            punctuation[i]=0.25;
        }
        else{
            punctuation[i]=0;
        }
        i++;
    }
    i=0;
    while(j--){
        std::cout<<punctuation[i++]<<"p ";
    }
    return 0;
}