#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    int side;
    cin>>side;
    cin.ignore();
    string line;
    vector<string> toast;
    bool jam=false;
    bool equal=true;
    getline(cin,line);
    for(int i=0;i<side;i++){
        getline(cin,line);
        toast.push_back(line);
        if(jam==false && line.find('#')!=std::string::npos){
            jam=true;
        }
        
    }
    getline(cin,line);
    for(int i=0;i<side;i++){
        getline(cin,line);
        if(toast[i]!=line){
            equal=false;
        }
    }
    if(jam==false){
        cout<<"NO LLEVABA MERMELADA";
        return 0;
    }
    if(equal==true){
        cout<<"HA HABIDO SUERTE";
    }
    else{
        cout<<"TRAGEDIA";
    }
    return 0;
}