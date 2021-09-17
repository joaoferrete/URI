#include <bits/stdc++.h>
using namespace std;

bool is_prime(unsigned long long n) {
    if (n == 1) return true;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (unsigned long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    unsigned long long n;
    cin >> n;
    if (is_prime(n)) cout << "N" << endl;
    else cout << "S" << endl;
    return 0;
}
