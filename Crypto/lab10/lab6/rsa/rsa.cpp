// RSA.cpp : RSA.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stack>
#include <random>
#include <fstream>

using namespace std;

//Структура ключа
typedef struct {
    uint64_t e;
    uint64_t m;
} key;

//Расширенный алгоритм Евклида
int64_t gcdex(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int64_t x1, y1;
    int64_t d = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

//Обратное по модулю
int64_t invmod(int64_t a, int64_t m) {
    int64_t x, y;
    gcdex(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}

uint64_t sqr(uint64_t x) {
    return x * x;
}

//Быстрое возведение в степень
uint64_t binpow(uint64_t a, uint64_t e, uint64_t mod = LLONG_MAX) {
    return e == 0 ? 1 : (e & 1U ? a * binpow(a, e - 1, mod) % mod : sqr(binpow(a, e / 2, mod)) % mod);
}

//Генерация пары ключей
pair<key, key> gen_keys(uint64_t p, uint64_t q) {
    uint64_t phi = (p - 1) * (q - 1);
    uint64_t n = p * q;
    //Простое число Мерсенна, обычно используется в RSA в виде открытой экспоненты для увеличения производительности
    uint64_t e = 65537;
    uint64_t d = invmod(e, phi);
    return { {e, n},
            {d, n} };
}

void help() {
    cout << "---- tinyRSA\n"
        "e <exp> <mod> <file in> <file out> -- Encrypt file\n"
        "d <exp> <mod> <file in> <file out> -- Decrypt file\n"
        "g -- Generate key pair from default primes\n"
        "G <p> <q> -- Generate key pair from primes\n"
        "h -- Help\n"
        "q -- Exit\n" << endl;
}

int main() {
    help();
    while (true) {
        char cmd;
        cin >> cmd;
        if (cmd == 'q') {
            cout << "Bye." << endl;
            break;
        }
        else if (cmd == 'e') {

        }
        else if (cmd == 'd') {

        }
        else if (cmd == 'g') {
            auto key_pair = gen_keys(3557, 2579);
            cout << "OPEN KEY  : " <<  key_pair.first.e << ' ' << key_pair.first.m << endl;
            cout << "SECRET KEY: " << key_pair.second.e << ' ' << key_pair.second.m << endl;
        }
        else if (cmd == 'G') {
            uint64_t p, q;
            cin >> p >> q;
            auto key_pair = gen_keys(p, q);
            cout << "OPEN KEY  : "  << key_pair.first.e << ' ' << key_pair.first.m << endl;
            cout << "SECRET KEY: "  << key_pair.second.e << ' ' << key_pair.second.m << endl;
        }
        else if (cmd == 'h')
            help();
    }
    return 0;
}
