/*
 *
 * Proyecto Generador de Contraseñas clase PrimeGenerator
 * Juan Enrique Ayala Zapata
 * A01711235
 * 04/06/2024
 * Esta clase define un objeto de tipo PrimeGenerator que contiene métodos
 * para generar números primos. Esta clase es utilizada por otras clases en 
 * el proyecto de Generador de Contraseñas para incluir números primos en las 
 * contraseñas.
 */
#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H

#include <vector>
using namespace std;

class PrimeGenerator {
public:
    /** 
     * Método para obenet una cantidad específica de numeros primos.
     * 
     * Generauna lista de numeros primos comenzando desde el número 5, 
     * y continúa hasta alcanzar una antidad especificada.
     * 
     * @param cantidad - La cantidad de números primos a generar
     * @return vector<int> - Un vector que contiene los números 
     * primos generados.
    */
    vector<int> obtenerPrimos(int cantidad) {
        vector<int> primos;
        int numero = 5;
        int paso = 2;

        while (primos.size() < cantidad) {
            if (esPrimo(numero, primos)) {
                primos.push_back(numero);
            }
            numero += paso;
            paso = 6 - paso;
        }
        return primos;
    }

private:

    /** 
     * Método para determinar si un número es primo.
     * 
     * Verifica si un número es primo al dividirlo por todos los números
     * primos en una lista de números primos.
     * 
     * @param numero - El número a verificar si es primo.
     * @param primos - Un vector que contiene los números primos
     * generados hasta el momento.
     * @return bool - Verdadero si el número es primo, falso en caso
     * contrario.
    */
    bool esPrimo(int numero, const vector<int>& primos) {
        for (int p : primos) {
            if (numero % p == 0) return false;
        }
        return true;
    }
};

#endif // PRIME_GENERATOR_H