#include <iostream>
#include <string>
using namespace std;

long long power(int a, int b, int n) {
    long long remainder = pow(a,b);
 
    return remainder % n;
}

template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int mul(int a, int b, int n) {// a*b mod n 
    int sum = 0;

    for (int i = 0; i < b; i++) {
        sum += a;

        if (sum >= n) {
            sum %= n;
        }
    }
    return sum;
}


int main()
{
    int g = 5, p = 23, a = 6,b = 15;

    //открытый ключ Алисы
    long long A = power(g, a, p);
    //открытый ключ Боба
    long long B = power(g, b, p);

    //секртеный ключ
    long long S1 = power(B, a, p);
    long long S2 = power(A, b, p);

    std::cout << "A= " << A << " ";
    std::cout << "B= " << B << " ";
    std::cout << "S1= " << S1 << " ";
    std::cout << "S2= " << S2 << " \n";

    //-----------------------------------
    int n = 1073, d = 853, e = 13;
    char* m = new char[5];
    cin.get(m, 6);
    int* c = new int[5];

    for (int i = 0; i < 5; i++)
    {
        c[i] = modpow<long long>(m[i], e, n);
    }

    for (int i = 0; i < 5; i++)
    {
        m[i] = modpow<long long>(c[i], d, n);
    }

    std::cout << "Crypt: ";
    std::cout << c << " ";
    std::cout << "Decrypt: ";
    std::cout << m << " ";

    return 0;
}