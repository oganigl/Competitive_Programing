#include <iostream>
#include <queue>
#include <string>
void print_queue(std::queue<char> a){
    char person;
    if(a.empty()){
        std::cout<<"NO HAY NADIE"<<std::endl;
        return;
    }
    while(!a.empty()){
        person=a.front();
        a.pop();
        std::cout<<person<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    int size_queue;
    int from,to,attendance,aggregate;
    char person;
    std::string line;
    std::cin>>size_queue;
    std::cin.ignore();
    std::vector<std::queue<char>> queue_total(3);
    size_t pos;
    for(int j=0;j<3;j++){
        for(int i=0;i<size_queue;i++){
            std::cin>>person;
            queue_total[j].push(person);
        }
    }
    std::cin.ignore();
    int j=0;
    while(std::getline(std::cin,line)){
        if(line.empty()){ break;}
        switch(line[1]){
            case 'O': 
                pos=line.find(' ');
                line.erase(0,pos+1);
                from=line[0]-'0';
                pos=line.find(' ');
                line.erase(0,pos+1);
                to=line[0]-'0';
                if(!queue_total[from].empty()){
                    person=queue_total[from].front();
                    queue_total[from].pop();
                    queue_total[to].push(person);
                }
                break;
            case 'T': 
                pos=line.find(' ');
                line.erase(0,pos+1);
                attendance=line[0]-'0';
                if(!queue_total[attendance].empty()){
                    queue_total[attendance].pop();
                }
                break;
            case 'G': 
                pos=line.find(' ');
                line.erase(0,pos+1);
                person=line[0];
                pos=line.find(' ');
                line.erase(0,pos+1);
                to=line[0]-'0';
                queue_total[to].push(person);
                break;
        }
        j++;
    }
        for(const auto& elem :queue_total){
            print_queue(elem);
        }
}