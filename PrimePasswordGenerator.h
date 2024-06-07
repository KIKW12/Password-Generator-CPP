/*
 *
 * Proyecto Generador de Contraseñas clase PrimePasswordGenerator
 * Juan Enrique Ayala Zapata
 * A01711235
 * 04/06/2024
 * Esta clase define un objeto de tipo PrimePasswordGenerator que extiende
 * la funcionalidad de PasswordGenerator para incluir números primos en las
 * contraseñas generadas. Esta clase utiliza PrimeGenerator para obtener los
 * números primos necesarios y es parte del proyecto de Generador de Contraseñas.
 */
#ifndef PRIME_PASSWORD_GENERATOR_H
#define PRIME_PASSWORD_GENERATOR_H

#include "PasswordGenerator.h"
#include "PrimeGenerator.h"
#include <algorithm> // for std::shuffle
#include <random> // for std::default_random_engine

class PrimePasswordGenerator : public PasswordGenerator {
    PrimeGenerator primeGen;

public:
    /** 
     * Constructor que inicializa el generador de contraseñas con parámetros
     * personalizados.
     * 
     * @param longitud - La longitud de la contraseña a generar.
     * @param usarMayusculas - Booleano que indica si se deben usar 
     * mayúsculas en la contraseña.
     * @param usarEspeciales - Booleano que indica si se deben usar 
     * caracteres especiales en la contraseña.
     * @param usarNumeros - Booleano que indica si se deben usar 
     * números en la contraseña.
    */
    PrimePasswordGenerator(int longitud, bool usarMayusculas, 
    bool usarEspeciales, bool usarNumeros)
            : PasswordGenerator(longitud, usarMayusculas, usarEspeciales, 
            usarNumeros) {}

    /** 
     * Método para generar una contraseña segura que incluye números primos.
     *
     * Utiliza los parámetros definidos para generar una contraseña que puede 
     * incluir letras minúsculas, mayúsculas, caracteres especiales y números. 
     * Si se permite el uso de números, también se incluirán números primos 
     * generados por PrimeGenerator.
     *
     * @param
     * @return string - La contraseña generada.
    */

    string generarContraseña() {
        string contraseña = PasswordGenerator::generarContraseña();
        if (usarNumeros) {
            vector<int> primos = primeGen.obtenerPrimos(longitud);

            /**
             * Baraja el vector de numeros primos
             */
            random_device rd;
            default_random_engine eng(rd());
            shuffle(primos.begin(), primos.end(), eng);

            /**
             * Calcula el numero de primos insertar
             */
            int numPrimesToInsert = longitud / 4;

            for (int i = 0; i < numPrimesToInsert && i < primos.size(); ++i) {
                int prime = primos[i];
                string primeStr = to_string(prime);

                /** 
                 * Selecciona aleatoriamente una posición dentro de la 
                 * contraseña para reemplazar.
                */
                size_t pos = rand() % contraseña.length();

                /** 
                 * Calcula el tamaño máximo de la cadena a reemplazar.
                */
                size_t maxReplaceLength = min(
                    primeStr.length(), contraseña.length() - pos);

                /**
                 * Reemplaza la parte de la contraseña con el número primo.
                */
                contraseña.replace(pos, maxReplaceLength, primeStr.substr(
                    0, maxReplaceLength));
            }
        }
        return contraseña;
    }
};

#endif // PRIME_PASSWORD_GENERATOR_H