#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

void print(std::vector<string> &solution){
    string asterisks;
     for (const auto& line : solution) {
        
        string asterisks(line.size(), '*');
        cout << asterisks << endl;   
        cout << line << endl;        
        cout << asterisks << endl; 
    }
}
int main() {
    int cases;
    cin>>cases;
    if(!cases){
        return 0;
    }
    cin.ignore();
    std::vector<string> solution;
    for(int i=0;i<cases;i++){
        string line;
        string line_solution="*";
        getline(cin,line);
        for(char j : line){
            if(isalpha(j)){
                line_solution+=" ";
                line_solution+=j;
                line_solution+=" *";
            }
            if(j==' '){
                line_solution+="**";
            }
        }
        solution.push_back(line_solution);
    }
    print(solution);
    return 0;
}