#ifndef PASSWORD_CONFIG_H
#define PASSWORD_CONFIG_H

class PasswordConfig {
public:
    int longitud;
    bool usarMayusculas;
    bool usarEspeciales;
    bool usarNumeros;
    bool usarPrimos;

    PasswordConfig(int longitud, bool usarMayusculas, bool usarEspeciales, 
    bool usarNumeros, bool usarPrimos)
            : longitud(longitud), usarMayusculas(usarMayusculas), 
            usarEspeciales(usarEspeciales), usarNumeros(usarNumeros), 
            usarPrimos(usarPrimos) {}

    int getLongitud() const { return longitud; }
    bool isUsarMayusculas() const { return usarMayusculas; }
    bool isUsarEspeciales() const { return usarEspeciales; }
    bool isUsarNumeros() const { return usarNumeros; }
    bool isUsarPrimos() const { return usarPrimos; }
};

#endif // PASSWORD_CONFIG_H
