#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

class lista {
private:
    vector<int> conjunto;
    int numero;
    string input;

    void ingresarNumeros() {
        while (true) {
            cout << "> Ingresa un numero (o 'salir' para terminar): ";
            cin >> input;
            
            if (input == "salir") {
                break;
            }

            try {
                numero = stoi(input); // string a entero
                conjunto.push_back(numero); // agregar numero al final del vector
            } catch (invalid_argument const &e) { // para cuando el dato ingresado no es un numero
                cout << "Entrada invalida. Por favor ingresa un numero." << endl;
            } catch (out_of_range const &e) { // para cuando el numero es muy grande
                cout << "El dato ingresado esta fuera del rango de un entero." << endl;
                cout << "El valor maximo que puede almacenar un entero es: " << numeric_limits<int>::max() << endl;
            }
        }
    }

public:
    void llenar() {
        conjunto.clear();
        ingresarNumeros();
    }

    void mostrarNumeros() {
        cout << "Numeros ingresados: { ";
        for (int num : conjunto) {
            cout << num << ", ";
        }
        cout << "}" << endl;
    }
};

int main() {
    lista conjunto;
    conjunto.llenar();
    conjunto.mostrarNumeros();
    system("pause");
    return 0;
}