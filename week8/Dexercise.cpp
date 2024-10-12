#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

struct node {
    int cost;
    int previous;
};

typedef std::pair<int, int> pii; // (cost, node)

void trace_back(std::vector<node>& solution,int start, int finish){
    while(finish!=start){
        finish=solution[finish].previous;
        std::cout<<finish;
        if(finish!=start){
            std::cout<<" <- ";
        }
    }
    std::cout<<std::endl;
}

void dijkstra(std::vector<std::vector<pii>>& district, int start, std::vector<node>& solution) {
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; 
    pq.push({0, start}); 
    solution[start].cost = 0;
    
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int current_cost = top.first;
        int actual_pos = top.second;

        if (current_cost > solution[actual_pos].cost) {
            continue; 
        }

        for (auto& elem : district[actual_pos]) {
            int new_cost = solution[actual_pos].cost + elem.first;
            if (new_cost < solution[elem.second].cost) {
                solution[elem.second].cost = new_cost;
                solution[elem.second].previous = actual_pos;
                pq.push({new_cost, elem.second});
            }
        }
    }
}

int main() {
    int prove_cases, corners, beginning, number_streets, street, dangerous_level;
    std::cin >> prove_cases;

    for (int i = 0; i < prove_cases; i++) {
        std::cin >> corners >> beginning;
        std::vector<std::vector<pii>> district(corners);

        // Lectura del grafo
        for (int j = 0; j < corners; j++) {
            std::cin >> number_streets;
            for (int k = 0; k < number_streets; k++) {
                std::cin >> street >> dangerous_level;
                district[j].push_back({dangerous_level, street});
            }
        }

        // Ejecutamos Dijkstra una sola vez desde el nodo de inicio
        std::vector<node> solution(corners, {std::numeric_limits<int>::max(), -1});
        dijkstra(district, beginning, solution);

        // Reutilizamos la solución para cada nodo destino
        for (int finish = 0; finish < corners; finish++) {
            if (finish != beginning) {
                if (solution[finish].cost != std::numeric_limits<int>::max()) {
                    std::cout << finish << ":\n";
                    std::cout << "riesgo " << solution[finish].cost << std::endl;
                    trace_back(solution, beginning, finish);
                } else {
                    std::cout << "No se encontró un camino al destino.\n";
                }
            }
        }
    }

    return 0;
}
