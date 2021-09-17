#include <bits/stdc++.h>
using namespace std;


bool fastPrime(unsigned long long n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (unsigned long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    unsigned long long n, casos;
    cin >> casos;
    while (casos--) {
        cin >> n;
        if (fastPrime(n)) cout << "Prime" << endl;
        else cout << "Not Prime" << endl;
    }
    return 0;
}