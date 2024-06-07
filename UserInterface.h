/*
 *
 * Proyecto Generador de Contraseñas clase UserInterface
 * Juan Enrique Ayala Zapata
 * A01711235
 * 04/06/2024
 * Esta clase define un objeto de tipo UserInterface que proporciona una
 * interfaz de usuario para generar contraseñas basadas en diferentes 
 * configuraciones. Permite al usuario especificar las características de 
 * las contraseñas y gestiona la interacción con el generador de contraseñas. 
 * Esta clase es parte del proyecto de Generador de Contraseñas.
 */

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "PasswordConfig.h"
#include "PasswordGenerator.h"
#include "PrimePasswordGenerator.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

class UserInterface {
public:

    /**
     * Método principal que ejecuta la interfaz de usuario.
     *
     * Solicita al usuario la configuración para generar contraseñas, 
     * incluyendo la cantidad de ejecuciones, la cantidad de contraseñas por
     * ejecución y las características de las contraseñas (longitud, uso de
     * mayúsculas, caracteres especiales, números y números primos). Genera 
     * las contraseñas según la configuración especificada y las muestra en
     * la consola.
     *
     * @param
     * @return
     */
    void run() {
        srand(time(0));
        try {
            int cantidadEjecuciones = pedirEntero(
                "¿Cuántas veces deseas generar contraseñas? \n");
            int cantidadContraseñas = pedirEntero(
                "¿Cuántas contraseñas deseas generar? \n");
            int longitud = pedirEntero(
                "Ingresa la longitud de las contraseñas \n");

            bool usarMayusculas = pedirBooleano(
                "¿Quieres usar letras mayúsculas? (s/n) \n");
            bool usarEspeciales = pedirBooleano(
                "¿Quieres usar caracteres especiales? (s/n) \n");
            bool usarNumeros = pedirBooleano(
                "¿Quieres usar números? (s/n) \n");
            bool usarPrimos = pedirBooleano(
                "¿Quieres usar números primos? (s/n) \n");

            for (int i = 0; i < cantidadEjecuciones; ++i) {
                cout << "Ejecución " << (i + 1) << ":" << endl;
                for (int j = 0; j < cantidadContraseñas; ++j) {
                    PasswordConfig config(
                        longitud, usarMayusculas, usarEspeciales, 
                        usarNumeros, usarPrimos);
                    
                    PasswordGeneratorBase* generador = nullptr;
                    
                    if (usarPrimos) {
                        generador = new PrimePasswordGenerator(
                            config.getLongitud(), 
                            config.isUsarMayusculas(), 
                            config.isUsarEspeciales(), 
                            config.isUsarNumeros());
                    } else {
                        generador = new PasswordGenerator(
                            config.getLongitud(), 
                            config.isUsarMayusculas(), 
                            config.isUsarEspeciales(), 
                            config.isUsarNumeros());
                    }

                    string contraseña = generador->generarContraseña();
                    cout << (j + 1) << ". " << contraseña << endl;

                    delete generador;  // Liberar la memoria
                }
            }
        } catch (const invalid_argument& e) {
            cout << "Por favor, ingresa una longitud o cantidad válida." 
            << endl;
        }
    }

private:

    /**
     * Solicita al usuario ingresar un valor entero.
     *
     * Muestra un mensaje en la consola y lee un valor entero 
     * ingresado por el usuario.
     *
     * @param mensaje - El mensaje a mostrar al usuario.
     * @return int - El valor entero ingresado por el usuario.
     */
    int pedirEntero(const string& mensaje) {
        cout << mensaje << " ";
        int valor;
        cin >> valor;
        return valor;
    }

    /**
     * Solicita al usuario ingresar un valor booleano.
     *
     * Muestra un mensaje en la consola y lee una respuesta de 's' o 'n' 
     * ingresada por el usuario.
     *
     * @param mensaje - El mensaje a mostrar al usuario.
     * @return bool - True si el usuario ingresó 's' o 'S', 
     * false en caso contrario.
     */
    bool pedirBooleano(const string& mensaje) {
        cout << mensaje << " ";
        char respuesta;
        cin >> respuesta;
        return respuesta == 's' || respuesta == 'S';
    }
};

#endif // USER_INTERFACE_H
