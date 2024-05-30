#ifndef PRIME_PASSWORD_GENERATOR_H
#define PRIME_PASSWORD_GENERATOR_H

#include "PasswordGenerator.h"
#include "PrimeGenerator.h"
#include <algorithm> // for std::shuffle
#include <random> // for std::default_random_engine

class PrimePasswordGenerator : public PasswordGenerator {
    PrimeGenerator primeGen;

public:
    PrimePasswordGenerator(int longitud, bool usarMayusculas, bool usarEspeciales, bool usarNumeros)
            : PasswordGenerator(longitud, usarMayusculas, usarEspeciales, usarNumeros) {}

    string generarContraseña() override {
        string contraseña = PasswordGenerator::generarContraseña();
        if (usarNumeros) {
            vector<int> primos = primeGen.obtenerPrimos(longitud);

            // Shuffle the vector of prime numbers
            random_device rd;
            default_random_engine eng(rd());
            shuffle(primos.begin(), primos.end(), eng);

            // Calculate the number of primes to insert
            int numPrimesToInsert = longitud / 2; // Example: Insert half the length of primes

            for (int i = 0; i < numPrimesToInsert && i < primos.size(); ++i) {
                int prime = primos[i];
                string primeStr = to_string(prime);

                // Randomly select a position within the password to replace
                size_t pos = rand() % contraseña.length();

                // Ensure the prime doesn't exceed the remaining length
                size_t maxReplaceLength = min(primeStr.length(), contraseña.length() - pos);

                // Replace part of the password with the prime number
                contraseña.replace(pos, maxReplaceLength, primeStr.substr(0, maxReplaceLength));
            }
        }
        return contraseña;
    }
};

#endif // PRIME_PASSWORD_GENERATOR_H