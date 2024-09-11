#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm> // Para usar std::remove
using namespace std;

bool isValidMove(vector<vector<char>>& lake, int x, int y, vector<vector<bool>>& visited) {
    int n = lake.size();
   
    return (x >= 0 && x < n && y >= 0 && y < n &&
            (lake[x][y] == '0' || lake[x][y] == 'C') && !visited[x][y]);
}


void dfs(vector<vector<char>>& lake, int x_frog, int y_frog, int x_home, int y_home,
         vector<vector<bool>>& visited, int current_jumps, int& min_jumps) {
    if (x_frog == x_home && y_frog == y_home) {
        min_jumps = min(min_jumps, current_jumps);  
        return;
    }

    visited[x_frog][y_frog] = true;

    
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto& dir : directions) {
        int new_x = x_frog + dir.first;
        int new_y = y_frog + dir.second;

        if (isValidMove(lake, new_x, new_y, visited)) {
            dfs(lake, new_x, new_y, x_home, y_home, visited, current_jumps + 1, min_jumps);
        }
    }

    visited[x_frog][y_frog] = false; 
}
int find_min_jumps_dfs(vector<vector<char>>& lake, int x_frog, int y_frog, int x_home, int y_home) {
    int n = lake.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int min_jumps = INT_MAX;

    dfs(lake, x_frog, y_frog, x_home, y_home, visited, 0, min_jumps);

    return (min_jumps == INT_MAX) ? -1 : min_jumps; 
}

int main() {
    int count, x_frog = -1, y_frog = -1, x_home = -1, y_home = -1;
    cin >> count;
    cin.ignore();

    vector<vector<char>> lake(count, vector<char>(count));
    string line;
    for (int i = 0; i < count; i++) {
        getline(cin, line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        for (int j = 0; j < count; j++) {
            lake[i][j] = line[j];
            if (line[j] == 'R') {  
                x_frog = i;
                y_frog = j;
                lake[i][j] = '0';  
            }
            if (line[j] == 'C') {  
                x_home = i;
                y_home = j;
                
            }
        }
    }
    int solution = find_min_jumps_dfs(lake, x_frog, y_frog, x_home, y_home);
        cout << solution << endl;
    return 0;
}
