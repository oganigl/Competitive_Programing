#include <iostream>
#include <stack>
#include <unordered_map>
int main(){
    int instructions;
    std::cin>>instructions;
    char movement,front_stack;
    std::stack<char> maze;
     std::cin>>movement;
     maze.push(movement);
     std::unordered_map<char,char> left_right_back_forward;
     left_right_back_forward['R']='L';
     left_right_back_forward['L']='R';
     left_right_back_forward['F']='B';
     left_right_back_forward['B']='F';
    for(int i=0;i<instructions-1;i++){
        std::cin>>movement;
        if(maze.empty()){
            maze.push(movement);
        }else{
            front_stack=maze.top();
            if(left_right_back_forward[movement]==front_stack){
                maze.pop();
            }else{
                maze.push(movement);
            }
        }
    }
    std::stack<char> result;
    int size=maze.size();
    for(int i=0;i<size;i++){
        result.push(maze.top());
        maze.pop();
    }
    for(int i=0;i<size;i++){
        std::cout<<result.top()<<" ";
        result.pop();
    }
}