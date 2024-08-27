#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#define PI_MINE 3.141592
using namespace std;
int  main(int argc, const char** argv) {
    int areas;
    int F;
    float R,X,Y;
    float result;
    std::cin>>areas;
    std::cout<<fixed<<setprecision(5);
    float all_result[areas];
    int i=0;
    int print=areas;
    while(areas--)
    {
      
        std::cin>>F;
        switch(F){
           case 1:
                std::cin>>R;
                result=R*R*PI_MINE;
                break;
            case 2: 
                cin>>X;
                result=X*X;
                break;
            case 3:
                cin>>X;
                cin>>Y;
                result=X*Y;
                break;
            default:
                cin>>X;
                cin>>Y;
                result=X*Y/2;
                break; 
        }
        all_result[i++]=result;
    }
    i=0;
    while(print--){
        std::cout<<all_result[i++]<<std::endl;
    }
    return 0;
}