#include <iostream>
#include <string>
 
int main(int argc, const char** argv) {
    std::string input;
    std::string solution;
 
    while (std::getline(std::cin, input)) {
        if (input.length() % 2 == 0) {  // Si la línea es par en longitud
            std::string correct_input(input.length(), ' ');  // Inicializa con el tamaño adecuado
            int j = 0;
            for (int i = input.length() - 1; i >= 0; i--) {
                correct_input[j] = input[i];
                j++;
            }
            input = correct_input;
        }
        solution += input + "\n";
    }
 
    std::cout << solution;
    return 0;
}