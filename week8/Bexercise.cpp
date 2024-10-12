#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void addEdge(std::vector<std::vector<int>> &graphs, int i, int j);
void BFS(int X, int Y, const std::vector<std::vector<int>> &graphs, std::vector<int> &path);

int main() {
    int n, m, X, Y, a, b;
    std::cin >> n >> m >> X >> Y;
    
    // Grafo como lista de adyacencias
    std::vector<std::vector<int>> graphs(n + 1);  // Índices de 1 a n
    
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        addEdge(graphs, a, b);
    }
    
    // Vector para almacenar el camino
    std::vector<int> path;
    
    // Ejecutar BFS para encontrar el camino más corto
    BFS(X, Y, graphs, path);
    
    // Imprimir el resultado: distancia y camino
    std::cout << path.size() - 1 << std::endl;  // Distancia (número de aristas)
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i != path.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

// Agregar una arista al grafo
void addEdge(std::vector<std::vector<int>> &graphs, int i, int j) {
    graphs[i].push_back(j);
    graphs[j].push_back(i);  // Grafo no dirigido
}

// Función BFS para encontrar el camino más corto
void BFS(int X, int Y, const std::vector<std::vector<int>> &graphs, std::vector<int> &path) {
    std::vector<bool> visited(graphs.size(), false);  // Vector de nodos visitados
    std::queue<std::pair<int, std::vector<int>>> open;  // Cola para BFS con caminos

    // Empezamos en el nodo X, con el camino inicial que solo contiene X
    open.push({X, {X}});
    visited[X] = true;

    while (!open.empty()) {
        // Desencolamos el siguiente nodo y su camino asociado
        auto [current, current_path] = open.front();
        open.pop();
        
        // Si llegamos al destino, almacenamos el camino en path
        if (current == Y) {
            path = current_path;
            return;
        }

        // Explorar los vecinos del nodo actual
        for (const int &neighbor : graphs[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                std::vector<int> new_path = current_path;  // Copiamos el camino actual
                new_path.push_back(neighbor);  // Añadimos el vecino al camino
                open.push({neighbor, new_path});  // Lo añadimos a la cola para seguir explorando
            }
        }
    }
}
