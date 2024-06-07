# Proyecto_Enrique_Ayala_TC1030

## Generador de contraseñas

### Contexto

Las contraseñas son la llave de entrada a nuestro mundo digital. El nosotros generar y/o tener una contraseña fuerte y robusta es un muy buen hábito para poder mantener nuestra seguridad en internet. Ahora bien, siempre tenemos esa pregunta: "¿Cada cuánto tiempo tenemos que cambiar nuestra contraseña?", es una pregunta realmente difícil, porque nunca podemos tener la idea de una contraseña que sea lo bastante segura. De acuerdo a Lance Spitzner, la correcta práctica es cambiar cada 90 días o cada 3 meses (Spitzner, s. f.).

Es aquí donde nace la idea de crear un generador de contraseñas que se adapte completamente a las carácterísticas requeridas por el usuario, desde la longitud de esta, si debe de utilizar mayúsculas, caracteres especiales, utilizar números y con esto, poder brindar una capa extra de seguridad al solo utilizar números primos generados de manera "aleatoria".

## Librerias utilizadas en el proyecto
### Librería STRING
Brinda soporte para este tipo de objetos con una interfaz similar a la de un contenedor estándar de bytes, pero añadiendo características específicamente diseñadas para operar con cadenas de caracteres con un solo byte. 

### Librería ALGORITHM
Define una colección de funciones diseñadas especialmente para ser usadas en un rango de elementos. Un rango es una secuencia de obetos que puede ser accedida a través de iteradores o punteros, como un array o una instancia.

### Librería VECTOR
Es una plantilla de clase para contenedores de secuencia, que almacena los elementos de un tipo determinado de dato en una organización lineal y permite el acceso aleatorio rápido a cualquier elemento. 

### Librería RANDOM
Define instalaciones para generar números aleatorios, lo que permite distribuidos de manera uniforme. 

### Librería CTIME
Incluye el encabezado <time.h> de la biblioteca estándar de C y agrega los nombres asociados al espacio de nombres std.

### Librería CSTDLIB
Define varias funciones de uso general, incluyendo manejo dinámico de memporia, generación aleatoria de números, comunicacion con el ambiente, operaciones aritméticas, búsqueda, ordenamiento y converciones. 

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
Casos en los que el programa dejaría de funcionar
1. Entradas no válidas: cuando el usuario ingresa valores no numéricos cuando se solicita, por ejemplo, la longitud de la contraseña o cuando es algo distinto a "s" o  "n" para los booleanos.
2. Longitud de la contraseña no válida: si el usuario ingresa una longitud de la contraseña menor o igual a cero, el generador podría producir una contraseña vacía, causando problemas de ejecución.
3. Configuración inconsistente: si se selecciona trabajar con numeros primos, pero no con números normales, genera una inconsistencia lógica y puede que el código no genere la contraseña correctamente. 

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

Library string. (s. f.). cplusplus.com. https://cplusplus.com/reference/string/

Library algorithm. (s/f). Cplusplus.com. https://cplusplus.com/reference/algorithm/

TylerMSFT. (s/f). vector (clase). Microsoft.com. https://learn.microsoft.com/es-es/cpp/standard-library/vector-class?view=msvc-170

TylerMSFT. (2023, 16 junio). . https://learn.microsoft.com/es-es/cpp/standard-library/random?view=msvc-170
