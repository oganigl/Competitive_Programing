#include <iostream>
#include <string>

int main() {
    int floors, houses;
    int solution = 0;

    std::cin >> floors >> houses;
    std::cin.ignore();  // Ignorar el salto de línea después de leer los números

    for (int i = 0; i < floors; ++i) {
        std::string input;
        std::getline(std::cin, input);

        for (int j = 0; j < houses; ++j) {
            // Chequea las dos ventanas de cada vivienda
            if (input[j * 4] == '#' || input[j * 4 + 2] == '#') {
                solution++;
            }
        }
    }

    std::cout << solution << std::endl;
    return 0;
}
