#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H

#include <vector>
#include <string>
using namespace std;

class PrimeGenerator {
public:
    string obtenerPrimos(int cantidad) {
        vector<int> primos;
        string primosStr;
        int numero = 5;
        int paso = 2;

        while (primos.size() < cantidad) {
            if (esPrimo(numero, primos)) {
                primos.push_back(numero);
                primosStr += to_string(numero);
            }
            numero += paso;
            paso = 6 - paso;
        }
        return primosStr;
    }

private:
    bool esPrimo(int numero, const vector<int>& primos) {
        for (int p : primos) {
            if (numero % p == 0) return false;
        }
        return true;
    }
};

#endif // PRIME_GENERATOR_H
