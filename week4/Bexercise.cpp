#include <iostream>
#include <string>
using namespace std;

void count_flavours(int n){
    int count[n]={0};
    int number_ice_cream;
    for(int i=0; i<2;i++){
        for(int j=0;j<n;j++){
            cin>>number_ice_cream;
            count[j]+=number_ice_cream;
        }
    }
    for(int result : count){
        cout<<result<<" ";
    }

}

int main() {
    int flavours;
    cin>>flavours;
    cin.ignore();
    count_flavours(flavours);
    return 0;
}