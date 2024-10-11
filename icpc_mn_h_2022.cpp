#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int MOD = 1e9 + 7;

using namespace std;
// a beautiful number: product of its digits is the biggest possible, with left <= num <= right
// int beautifulNumber(int left, int right) {
//     auto product = [](int n) -> int {
//         int res = 1;
//         while (n) {
//             res *= n % 10;
//             n /= 10;
//         }
//         return res;
//         };
//     int res = 0;
//     for (int i = left; i <= right; i++) {
//         res = max(res, product(i));
//     }
//     return res % MOD;
// }


// a beautiful number: product of its digits is the biggest with its in range (left, right)
string beautifulNum(int left, int right) {
    string r;
    int product = 1;
    while (right) {
        r += to_string(right % 10);
        right /= 10;
    }
    string aux;
    for (int i = 0; i < r.size(); i++) {
        aux += '1';
    }
    if (stoi(aux) > right) {
        aux.pop_back();
    }
    for (int i = aux.size() - 1; i >= 0; i--) {

    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int left, right;
    cin >> left >> right;
    // cout << beautifulNumber(left, right);
    cout << beautifulNum(left, right);
    return 0;
}