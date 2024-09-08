#include <iostream>
#include <string>
using namespace std;
 
void contar_vocales_y_letras(int n) {
    string vocales = "aeiou";  // Vocales permitidas
    for (int i = 0; i < n; ++i) {
        string caso;
        getline(cin, caso);  // Leer la línea de texto
        
        int num_vocales = 0;
        int num_letras = 0;
        
        // Recorrer cada carácter en la cadena
        for (char c : caso) {
            if (isalpha(c)) {  // Verificar si es una letra
                num_letras++;
                if (vocales.find(c) != string::npos) {  // Verificar si es una vocal
                    num_vocales++;
                }
            }
        }
        
        // Imprimir el resultado
        cout << num_vocales << " " << num_letras << endl;
    }
}
 
int main() {
    int n;
    cin >> n;  // Leer el número de casos
    cin.ignore();  // Ignorar el salto de línea después de leer el número de casos
    
    contar_vocales_y_letras(n);  // Llamar a la función para procesar los casos
    
    return 0;
}