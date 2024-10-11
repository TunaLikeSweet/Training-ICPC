#include <iostream>
#include <vector>
using namespace std;

vector<long long> genFib(long long maxVal) {
    vector<long long> fibs = {2, 3};
    while (true) {
        long long next = fibs.back() + fibs[fibs.size() - 2];
        if (next > maxVal) break;
        fibs.push_back(next);
    }
    return fibs;
}

long long countWays(long long n) {
    vector<long long> fibs = genFib(n);
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;

    for (long long fib : fibs) {
        for (long long i = fib; i <= n; ++i) {
            if (i % fib == 0) {
                dp[i] += dp[i / fib];
            }
        }
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << countWays(n) << endl;
    }
    return 0;
}
