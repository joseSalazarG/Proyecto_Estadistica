#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip> // para precision 

using namespace std;

class lista {
private:
    vector<double> conjunto; 
    double numero; 
    string input;

    void ingresarNumeros() {
        while (true) {
            cout << "> Ingresa un numero (o 'salir' para terminar):";
            getline(cin, input);
 
            if (input == "salir") {
                break;
            }

            try {
                replace(input.begin(), input.end(), ',', '.');
                numero = stod(input); // Cambiar a stod para convertir a double
                conjunto.push_back(numero);
            } catch (invalid_argument const &e) {
                cout << "Entrada invalida. Por favor ingresa un numero." << endl;
            } catch (out_of_range const &e) {
                cout << "El dato ingresado esta fuera del rango de un double." << endl;
                cout << "El valor maximo que puede almacenar un double es: " << numeric_limits<double>::max() << endl;
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
        for (int i = 0; i < conjunto.size(); i++) {
                cout << conjunto[i] << (i < conjunto.size() - 1 ? ", " : ""); // si no es el ultimo numero, se pone una coma
        }
        cout << "}" << endl;


        sort(conjunto.begin(), conjunto.end()); // lista ordenada
        cout << "Numeros ordenados: { ";
        for (int i = 0; i < conjunto.size(); i++) {
                cout << conjunto[i] << (i < conjunto.size() - 1 ? ", " : ""); // si no es el ultimo numero, se pone una coma
        }
        cout << "}\n" << endl;
    }

    pair<double, double> calcularMedia() {
        if (conjunto.empty()) return {0.0, 0.0};
        double suma = 0;

        for (double num : conjunto) {
            suma += num; // Sumar todos los valores
        }

        double media = suma / conjunto.size(); // Dividir la suma entre la cantidad de datos
        return {media, suma}; 
    }

    void mostrarMediaYSuma() {
        pair<double, double> resultado = calcularMedia();//para la media y suma
        double media = resultado.first; // guarda la media
        double suma = resultado.second; // guarda la suma

        cout << "Suma de los numeros:" << suma << endl;
        cout << "Divisor para la media:" << conjunto.size() << endl;
        cout << "- Media: " << fixed << setprecision(2) << media << endl; // para dos decimales
    }

    void mostrarMediana() {
        vector<double> aux = conjunto; 
        int n = aux.size();
        double mediana = 0;

        if (n % 2 == 0) { // si es par
            // Promedio de los dos numeros del medio
            mediana = (aux[(n / 2) - 1] + aux[n / 2]) / 2; // se suman los dos numeros del medio y se dividen enre 2
        } else { // si es impar
            mediana = aux[n / 2]; // se toma el numero del medio
        }

        cout << "- Mediana:" << fixed << setprecision(2) << mediana << endl; // dos decimales
    }

    void mostrarModa() {
        map<double, int> frecuenciaMap; //almacena numeros y su frecencia 

        for (double num : conjunto) {
            frecuenciaMap[num]++;  // para contar la frecuencia para c/numero
        }

        int maxFrecuencia = 0;
        for (const auto& par : frecuenciaMap) {               // recorre el mapa de frecuencias usando un iterador constante
            maxFrecuencia = max(maxFrecuencia, par.second);  // se guarda la frecuencia maxima 
        }

        vector<double> modas; 
        for (const auto& par : frecuenciaMap) {
            if (par.second == maxFrecuencia && maxFrecuencia > 1) {   // si la frecuencia es igual a la maxima y es mayor a 1
                modas.push_back(par.first);                         // se guarda el numero en el vector de modas
            }
        }

        if (modas.empty()) { // si no hay moda
            cout << "- Moda:amodal, no hay moda (todos los numeros son unicos)." << endl;
        } else {
            cout << "- Moda: ";
            for (size_t i = 0; i < modas.size(); i++) {
                cout << modas[i] << (i < modas.size() - 1 ? ", " : ""); // si no es el ultimo numero, se pone una coma
            }
            cout << " (se repite(n) " << maxFrecuencia << " veces)" << endl; // muestra los resultados
        }
    }
};

int main() {
    lista conjunto;
    conjunto.llenar();
    conjunto.mostrarNumeros();
    conjunto.mostrarMediaYSuma();
    conjunto.mostrarMediana();
    conjunto.mostrarModa();
    
    cout << "Presiona Enter para terminar...";
    cin.ignore();
    return 0;
}
