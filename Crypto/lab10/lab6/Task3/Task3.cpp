#include <iostream>
using namespace std;

template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
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
    int p = 179, g = 2, k = 9;

    long long a = modpow<long long>(g, k, p);

    char* m = new char[5];
    std::cin.get(m, 6);
    int* c = new int[5];

    for (int i = 0; i < 5; i++)
    {
        c[i] = mul(modpow<int>(a, k, p), m[i], p);

    }
    for (int i = 0; i < 5; i++)
    {
        m[i] = mul(c[i], modpow<long long>(a, (p - k - 1), p), p);
    }
    std::cout << "Crypt: ";
    std::cout << c << " ";
    std::cout << "Decrypt: ";
    std::cout << m << " ";

    return 0;
}