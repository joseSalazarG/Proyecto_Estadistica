#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

class lista {
private:
    vector<int> conjunto;
    int numero;
    string input;

    void ingresarNumeros() {
        while (true) {
            cout << "> Ingresa un numero (o 'salir' para terminar): ";
            getline(cin,input);// no me funcionaba de la otra manera y lo cambié
 
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

        cout << "\nNumeros ingresados: { ";
        for (int num : conjunto) {
            cout << num << ", ";
        }
        cout << "}" << endl;

        sort(conjunto.begin(), conjunto.end());
        cout << "Numeros ordenados: { ";
        for (int num : conjunto) {
            cout << num << ", ";
        }
        cout << "}\n" << endl;
    }

    //PARA CALCULAR LA MEDIA
    pair<double, double> calcularMedia() {
        if (conjunto.empty()) return {0.0, 0.0};
        double suma = 0;

        for (int num : conjunto) {
            suma += num;
        }

        double media = suma / conjunto.size();
        return {media, suma}; 
    }

    void mostrarMediaYSuma() {
        pair<double, double> resultado = calcularMedia(); //para la media y suma
        double media = resultado.first; // guarda la media
        double suma = resultado.second; // guarda la suma
        cout << "Suma de los numeros: " << suma << endl;
        cout << "Divisor para la media: " << conjunto.size() << endl;
        cout << "Media: " << media << endl;
    }

    void mostrarMediana() {
        
        vector<int> aux = conjunto;
        int n = aux.size();
        int mediana = 0;

        if (n % 2 == 0) { // si es par
            mediana = (aux[(n/2)-1] + aux[n/2]) / 2; // se suman los dos numeros del medio y se dividen entre 2
            
        } else { // si es impar
            mediana = aux[n/2]; // se toma el numero del medio
        }

        cout << "Mediana: " << mediana << endl;
    }

    void mostrarModa() {
        vector<int> aux = conjunto;
        sort(aux.begin(), aux.end());
        int n = aux.size();
        int moda = 0;
        int frecuencia = 0;
        int maxFrecuencia = 0;

        for (int i = 0; i < n; i++) { // por cada numero en el vector
            int contador = 0;

            for (int j = 0; j < n; j++) { // se recorre el vector para contar las veces que se repite un numero
                if (aux[j] == aux[i]) {
                    contador++;
                }
            }

            if (contador > frecuencia) { // si la frecuencia actual es mayor a la frecuencia maxima
                frecuencia = contador;
                moda = aux[i]; // se guarda el numero que mas se repite
            }
        }

        cout << "Moda: " << moda << endl;
        cout << "Se repite " << frecuencia << " veces." << endl;
    }
};

int main() {
    lista conjunto;
    conjunto.llenar();
    conjunto.mostrarNumeros();
    conjunto.mostrarMediaYSuma();
    conjunto.mostrarMediana();
    conjunto.mostrarModa();
    
    cout << "Presiona Enter veces para terminar..."; //tampoco me funcionaba y lo cmabié
    cin.ignore();
    return 0;
}
