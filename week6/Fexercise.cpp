#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For using INT_MAX

using namespace std;

// Directions: down, up, right, left
const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Helper function to check if a move is valid
bool isValidMove(int x, int y, int width, int height, vector<vector<char>>& maze) {
    return x >= 0 && x < height && y >= 0 && y < width && (maze[x][y] == '.' || maze[x][y] == 'S');
}

// Recursive function to find the shortest path
int findShortestPath(vector<vector<char>>& maze, int x, int y, int x_exit, int y_exit, int width, int height) {
    // Base case: we reached the exit
    if (x == x_exit && y == y_exit) {
        return 1; // Count this step
    }

    // Mark the current cell as visited
    maze[x][y] = '#';

    // Initialize the minimum steps to a large value
    int min_steps = INT_MAX;

    // Explore all 4 directions (down, up, right, left)
    for (auto& dir : directions) {
        int new_x = x + dir.first;
        int new_y = y + dir.second;

        // Check if the new position is valid for a move
        if (isValidMove(new_x, new_y, width, height, maze)) {
            int steps = findShortestPath(maze, new_x, new_y, x_exit, y_exit, width, height);

            // If the recursive call found a valid path, update the minimum steps
            if (steps != INT_MAX) {
                min_steps = min(min_steps, steps + 1);
            }
        }
    }

    // Unmark the current cell (backtrack) to allow other paths to explore this cell
    maze[x][y] = '.';

    // If no valid path was found, return INT_MAX (indicating no path)
    return min_steps;
}

int main() {
    int width, height;
    cin >> width >> height;
    cin.ignore();

    vector<vector<char>> maze(height, vector<char>(width));
    int x_entry = -1, y_entry = -1, x_exit = -1, y_exit = -1;

    // Read the maze and find the positions of 'E' (entry) and 'S' (exit)
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < width; j++) {
            maze[i][j] = line[j];
            if (line[j] == 'E') {
                x_entry = i;
                y_entry = j;
            }
            if (line[j] == 'S') {
                x_exit = i;
                y_exit = j;
            }
        }
    }

    // If entry or exit is not found, return 0
    if (x_entry == -1 || x_exit == -1) {
        cout << 0 << endl;
        return 0;
    }

    // Call the recursive function to find the shortest path
    int result = findShortestPath(maze, x_entry, y_entry, x_exit, y_exit, width, height);

    // If result is INT_MAX, it means no path was found
    if (result == INT_MAX) {
        cout << 0 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
