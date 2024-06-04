# Proyecto_Enrique_Ayala_TC1030

## Generador de contraseñas

### Contexto

Las contraseñas son la llave de entrada a nuestro mundo digital. El nosotros generar y/o tener una contraseña fuerte y robusta es un muy buen hábito para poder mantener nuestra seguridad en internet. Ahora bien, siempre tenemos esa pregunta: "¿Cada cuánto tiempo tenemos que cambiar nuestra contraseña?", es una pregunta realmente difícil, porque nunca podemos tener la idea de una contraseña que sea lo bastante segura. De acuerdo a Lance Spitzner, la correcta práctica es cambiar cada 90 días o cada 3 meses (Spitzner, s. f.).

Es aquí donde nace la idea de crear un generador de contraseñas que se adapte completamente a las carácterísticas requeridas por el usuario, desde la longitud de esta, si debe de utilizar mayúsculas, caracteres especiales, utilizar números y con esto, poder brindar una capa extra de seguridad al solo utilizar números primos generados de manera "aleatoria".

## Consideraciones
El programa se ejecuta en consola, es decir, está hecho con c++ standard y por ello es capaz de ser ejecutado en todos los sistemas operativos.

●Compilar con el siguiente comando:
```
g++ main.cpp
```

●En Windows una vez compilado, ejecutar en terminal:
```
.\a.exe
```

●En Linux ejecutar en terminal 
```
./a.out
```
## Correcciones
En el diagrama UML de este proyecto, se incorporaron los casos en los cuales el proyecto deja de funcionar.

Se corrige la sobreescritura de funciones, presentadas en las clases 'PasswordGenerator' y 'PrimePasswordGenerator' que sobreescriben a la función 
```
string generarContraseña()
```
que se encuentra en la clase 'PasswordGeneratorBase'.

Así mismo, la sobrecarga se encuentra en la clase 'PasswordGenerator'
```
class PasswordGenerator {
public:
    PasswordGenerator(int longitud, bool usarMayusculas, bool usarEspeciales, bool usarNumeros)
            : PasswordGeneratorBase(longitud, usarMayusculas, usarEspeciales, usarNumeros) {}

    PasswordGenerator(int longitud)
            : PasswordGeneratorBase(longitud, true, true, true) {}
};
```

## Referencias
Spitzner, L. (s. f.). Why the 90 Day Rule for Password Changing? https://www.sans.org/blog/why-the-90-day-rule-for-password-changing/
