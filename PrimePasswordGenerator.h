#ifndef PRIME_PASSWORD_GENERATOR_H
#define PRIME_PASSWORD_GENERATOR_H

#include "PasswordGenerator.h"
#include "PrimeGenerator.h"

class PrimePasswordGenerator : public PasswordGenerator {
    PrimeGenerator primeGen;

public:
    PrimePasswordGenerator(int longitud, bool usarMayusculas, 
    bool usarEspeciales, bool usarNumeros)
            : PasswordGenerator(longitud, usarMayusculas, 
            usarEspeciales, usarNumeros) {}

    string generarContraseña() override {
        string contraseña = PasswordGenerator::generarContraseña();
        if (usarNumeros) {
            string primos = primeGen.obtenerPrimos(longitud);
            contraseña += primos.substr(0, longitud);
        }
        return contraseña;
    }
}
};

#endif // PRIME_PASSWORD_GENERATOR_H
