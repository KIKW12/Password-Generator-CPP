
/*
 *
 * Proyecto Generador de Contraseñas-clase PasswordConfig
 * Juan Enrique Ayala Zapata
 * A01711235
 * 16/10/2019
 * Esta clase define un objeto de tipo PasswordConfig que contiene los 
 * parámetros de configuración para la generación de contraseñas. 
 * Esta clase es utilizada por la clase PasswordGenerator y es parte 
 * del proyecto de Generador de Contraseñas.
 */

#ifndef PASSWORD_CONFIG_H
#define PASSWORD_CONFIG_H

class PasswordConfig {
public:
/**
* Variables públicas de instancia que almacenan la configuración de la 
* contraseña
*/
    int longitud;
    bool usarMayusculas;
    bool usarEspeciales;
    bool usarNumeros;
    bool usarPrimos;

/**
* Constructor que inicializa los valores de la configuración de la contraseña
* 
* @param longitud: longitud de la contraseña
* @param usarMayusculas: booleano que indica si se usan mayúsculas
* @param usarEspeciales: booleano que indica si se usan caracteres especiales
* @param usarNumeros: booleano que indica si se usan números
* @param usarPrimos: booleano que indica si se usan números primos
*/
    PasswordConfig(int longitud, bool usarMayusculas, bool usarEspeciales, 
    bool usarNumeros, bool usarPrimos)
            : longitud(longitud), usarMayusculas(usarMayusculas), 
            usarEspeciales(usarEspeciales), usarNumeros(usarNumeros), 
            usarPrimos(usarPrimos) {}

    /**
    * Método que regresa la longitud de la contraseña
    *
    * @param
    * @return int - La longitud de la contraseña
    */
    int getLongitud() const { return longitud; }

    /**
    * Métodos que indica si se deben usar mayusculas en la contraseña
    *
    * @param
    * @return bool - True si se deben usar mayusculas, false de lo contrario
    */
    bool isUsarMayusculas() const { return usarMayusculas; }

    /**
    * Métodos que indica si se deben usar caracteres especiales en la contraseña
    *
    * @param
    * @return bool - True si se deben usar caracteres especiales, 
    * false de lo contrario
    */
    bool isUsarEspeciales() const { return usarEspeciales; }

    /**
    * Métodos que indica si se deben usar numeros en la contraseña
    *
    * @param
    * @return bool - True si se deben usar numeros, false de lo contrario
    */
    bool isUsarNumeros() const { return usarNumeros; }

    /**
    * Métodos que indica si se deben usar numeros primos en la contraseña
    *
    * @param
    * @return bool - True si se deben usar numeros primos, false de lo contrario
    */
    bool isUsarPrimos() const { return usarPrimos; }
};

#endif // PASSWORD_CONFIG_H