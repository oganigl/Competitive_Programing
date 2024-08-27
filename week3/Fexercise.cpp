#include <iostream>
#include <sstream>
#include <string>

int main(int argc, const char** argv) {
    std::string input;
    std::getline(std::cin, input);  // Leer toda la entrada en una sola línea
    
    std::istringstream iss(input);
    int num, previous;
    std::string stairs;
    
    iss >> previous;  // Leer el primer número
    
    while (iss >> num) {  // Procesar los números restantes
        if (num > previous) {
            stairs += "S";
        } else if (num < previous) {
            stairs += "B";
        } else {
            stairs += "I";
        }
        
        previous = num;  // Actualizar `previous` con el valor actual
    }
    
    std::cout << stairs;
    return 0;
}
