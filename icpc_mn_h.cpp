#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int magicNumber(int div, int unDiv, int mul, int unMul) { // 3 4 60 105
    auto divisor = [&](int n) -> vector<int> {
        vector<int> factors;
        int x = sqrt(n);
        for (int i = 1; i <= x; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i != n / i) {
                    factors.push_back(n / i);
                }
            }
        }
        sort(factors.begin(), factors.end()); 
        return factors;
        };
    for (int n : divisor(mul)) {
        if (unMul % n !=  0 && n % div == 0 && n % unDiv != 0) {
            return n;
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int div, mul, unDiv, unMul;
    cin >> div >> unDiv >> mul >> unMul;
    cout << magicNumber(div, unDiv, mul, unMul);
    return 0;
}