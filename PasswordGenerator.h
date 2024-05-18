#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include "PasswordGeneratorBase.h"

class PasswordGenerator : public PasswordGeneratorBase {
public:
    PasswordGenerator(int longitud, bool usarMayusculas, bool usarEspeciales, 
    bool usarNumeros)
            : PasswordGeneratorBase(longitud, usarMayusculas, 
            usarEspeciales, usarNumeros) {}

    string generarContraseña() override {
        string caracteres = "abcdefghijklmnopqrstuvwxyz";

        if (usarMayusculas) caracteres += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (usarEspeciales) caracteres += "!@#$%^&*()-_=+[]{}|;:,.<>?";
        if (usarNumeros) caracteres += "0123456789";

        string contraseña;
        for (int i = 0; i < longitud; ++i) {
            contraseña += caracteres[rand() % caracteres.length()];
        }
        return contraseña;
    }
};

#endif // PASSWORD_GENERATOR_H
