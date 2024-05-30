#ifndef PASSWORD_GENERATOR_BASE_H
#define PASSWORD_GENERATOR_BASE_H

#include <string>
using namespace std;

class PasswordGeneratorBase {
protected:
    int longitud;
    bool usarMayusculas;
    bool usarEspeciales;
    bool usarNumeros;

public:
    PasswordGeneratorBase(int longitud, bool usarMayusculas, bool 
    usarEspeciales, bool usarNumeros)
            : longitud(longitud), usarMayusculas(usarMayusculas), 
            usarEspeciales(usarEspeciales), usarNumeros(usarNumeros) {}

    virtual string generarContraseña() = 0;
    virtual ~PasswordGeneratorBase() = default;
};

#endif // PASSWORD_GENERATOR_BASE_H