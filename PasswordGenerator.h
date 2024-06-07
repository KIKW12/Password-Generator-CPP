/*
 *
 * Proyecto Generador de Contraseñas-clase PasswordGenerator
 * Juan Enrique Ayala Zapata
 * A01711235
 * 04/06/2024
 * Esta clase define un objeto de tipo PasswordGenerator que contiene todas 
 * las operaciones
 * para generar contraseñas seguras basadas en diferentes criterios. 
 * Esta clase es utilizada por la función principal del programa 
 * y es parte del proyecto de Generador de Contraseñas.
 */

#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include "PasswordGeneratorBase.h"

class PasswordGenerator : public PasswordGeneratorBase {
public:
/**
* Constructor que inicializa el generador de contraseñas con parámetros 
* personalizados
*
* @param longitud: longitud de la contraseña
* @param usarMayusculas: booleano que indica si se usan mayúsculas
* @param usarEspeciales: booleano que indica si se usan caracteres especiales
* @param usarNumeros: booleano que indica si se usan números
*/
    PasswordGenerator(int longitud, bool usarMayusculas, bool usarEspeciales, 
    bool usarNumeros): PasswordGeneratorBase(longitud, usarMayusculas, 
        usarEspeciales, usarNumeros) {}

/**
* Constructor que inicializa el generador de contraseñas con longitud 
*personalizada y usando mayúsculas, caracteres especiales y números 
*por defecto.
*
* @param longitud - La longitud de la contraseña a generar.
*/
    PasswordGenerator(int longitud)
        : PasswordGeneratorBase(longitud, true, true, true) {}

/**
* Método para generar una contraseña segura.
*
* Utiliza los parámetros definidos para generar una contraseña que puede incluir
* letras minúsculas, mayúsculas, caracteres especiales y números.
*
* @param
* @return string - La contraseña generada.
*/

    string generarContraseña() {
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