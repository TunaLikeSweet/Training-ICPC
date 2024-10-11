#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;


// vector<int> factorize(int n) {
//     vector<int> factors;
//     for (int i = 9; i >= 2; i--) {
//         while (n % i == 0) {
//             factors.push_back(i);
//             n /= i;
//         }
//     } if (n > 1)
//         return {};
//     else return factors;
// }

// string bouquet(int n, size_t k) {
//     vector<int> a = factorize(n);
//     if (a.size() > k || a.empty()) { return "-1"; } else {
//         while (a.size() < k) {
//             a.push_back(1);
//         }
//     }
//     string res;
//     for (int x : a) {
//         res += to_string(x);
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }

// int main() {
//     int n;
//     size_t k;
//     cin >> n >> k;
//     cout << bouquet(n, k);
//     return 0;
// }

string bouquet(int n, size_t k) {
    vector<int> factors;
    for (int i = 9; i >= 2; i--) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) return "-1";

    if (factors.size() > k) {
        return "-1";
    } else {
        while (factors.size() < k) {
            factors.push_back(1);
        }
    }

    string res;
    for (int x : factors) {
        res += to_string(x);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    size_t k;
    cin >> n >> k;
    cout << bouquet(n, k);
    return 0;
}