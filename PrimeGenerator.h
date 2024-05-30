#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H

#include <vector>
using namespace std;

class PrimeGenerator {
public:
    vector<int> obtenerPrimos(int cantidad) {
        vector<int> primos;
        int numero = 5;
        int paso = 2;

        while (primos.size() < cantidad) {
            if (esPrimo(numero, primos)) {
                primos.push_back(numero);
            }
            numero += paso;
            paso = 6 - paso;
        }
        return primos;
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