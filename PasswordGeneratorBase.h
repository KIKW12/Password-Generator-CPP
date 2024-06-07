/*
 *
 * Proyecto Generador de Contraseñas clase PasswordGeneratorBase
 * Juan Enrique Ayala Zapata
 * A01711235
 * 04/06/2024
 * Esta clase define un objeto base de tipo PasswordGeneratorBase que contiene
 * los métodos y atributos necesarios para la generación de contraseñas. Esta 
 * clase es una clase abstracta y es utilizada por las clases derivadas en el
 * proyecto de Generador de Contraseñas.
 */

#ifndef PASSWORD_GENERATOR_BASE_H
#define PASSWORD_GENERATOR_BASE_H

#include <string>
using namespace std;

class PasswordGeneratorBase {
protected:

/**
 * Variables protegidas de instancia que almacenan la configuracion de la
 * contraseña a generar.
 */
    int longitud;
    bool usarMayusculas;
    bool usarEspeciales;
    bool usarNumeros;

public:

    /**
     * Constructor que inicializa los parámetros de configuración de la 
     * contraseña.
     * 
     * @param longitud - La longitud de la contraseña a generar.
     * @param usarMayusculas - Booleano que indica si se deben usar mayúsculas
     * en la contraseña.
     * @param usarEspciales - Booleano que indica si se deben usar caracteres
     * especiales en la contraseña.
     * @param usarNumeros - Booleano que indica si se deben usar números en la
     * contraseña. 
    */
    PasswordGeneratorBase(int longitud, bool usarMayusculas, bool 
    usarEspeciales, bool usarNumeros)
            : longitud(longitud), usarMayusculas(usarMayusculas), 
            usarEspeciales(usarEspeciales), usarNumeros(usarNumeros) {}
    
    /**
     * Destructor virtual por defecto
     * 
     * @param 
     * @return 
     */
    virtual ~PasswordGeneratorBase() = default;

    /** 
     * Método virtual puro para generar una contraseña
     * 
     * Este método debe ser implementado por las clases derivadas
     * 
     * @param 
     * @return string - La contraseña generada
    */
    virtual string generarContraseña() = 0;
};

#endif // PASSWORD_GENERATOR_BASE_H