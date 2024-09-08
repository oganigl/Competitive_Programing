#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;
    cin.ignore();

    vector<vector<char>> board(rows, vector<char>(columns));

    string line;
    for (int i = 0; i < rows; i++) {
        getline(cin, line);
        for (int j = 0; j < columns; j++) {
            board[i][j] = line[j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (board[i][j] == '*') {
                // Actualizar celdas vecinas
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < columns && board[ni][nj] != '*') {
                            board[ni][nj] = (board[ni][nj] >= '1' && board[ni][nj] <= '9') ? board[ni][nj] + 1 : '1';
                        }
                    }
                }
            }
        }
    }

    // Imprimir la solución
    for (const auto& line : board) {
        for (char element : line) {
            cout << element;
        }
        cout << endl;
    }

    return 0;
}
