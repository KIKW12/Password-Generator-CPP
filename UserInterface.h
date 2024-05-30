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
    void run() {
        srand(time(0));
        try {
            int cantidadEjecuciones = pedirEntero(
                "¿Cuantas veces deseas generar contrasenas? \n");
            int cantidadContraseñas = pedirEntero(
                "¿Cuantas contraseñas deseas generar? \n");
            int longitud = pedirEntero(
                "Ingresa la longitud de las contrasena \n");

            bool usarMayusculas = pedirBooleano(
                "¿Quieres usar letras mayusculas? (s/n) \n");
            bool usarEspeciales = pedirBooleano(
                "¿Quieres usar caracteres especiales? (s/n) \n");
            bool usarNumeros = pedirBooleano(
                "¿Quieres usar numeros? (s/n) \n");
            bool usarPrimos = pedirBooleano(
                "¿Quieres usar numeros primos? (s/n) \n");

            for (int i = 0; i < cantidadEjecuciones; ++i) {
                cout << "Ejecucion " << (i + 1) << ":" << endl;
                for (int j = 0; j < cantidadContraseñas; ++j) {
                    PasswordConfig config(longitud, usarMayusculas, 
                    usarEspeciales, usarNumeros, usarPrimos);
                    
                    PasswordGeneratorBase* generador = nullptr;
                    
                    if (usarPrimos) {
                        generador = new PrimePasswordGenerator(config.getLongitud(), 
                        config.isUsarMayusculas(), config.isUsarEspeciales(), 
                        config.isUsarNumeros());
                    } else {
                        generador = new PasswordGenerator(config.getLongitud(), 
                        config.isUsarMayusculas(), config.isUsarEspeciales(), 
                        config.isUsarNumeros());
                    }

                    string contraseña = generador->generarContraseña();
                    cout << (j + 1) << ". " << contraseña << endl;

                    delete generador;  // Liberar la memoria
                }
            }
        } catch (const invalid_argument& e) {
            cout << "Por favor, ingresa una longitud o cantidad valida." << endl;
        }
    }

private:
    int pedirEntero(const string& mensaje) {
        cout << mensaje << " ";
        int valor;
        cin >> valor;
        return valor;
    }

    bool pedirBooleano(const string& mensaje) {
        cout << mensaje << " ";
        char respuesta;
        cin >> respuesta;
        return respuesta == 's' || respuesta == 'S';
    }
};

#endif // USER_INTERFACE_H