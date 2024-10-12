#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
using namespace std;

void productOfFib() {
    long long n;
    cin >> n;
    vector<long long> fib{ 2, 3 };
    while (fib.back() <= n) 
        fib.push_back(fib[fib.size() - 2] + fib.back());
    fib.pop_back();
    vector<long long> canUsed;
    for (auto x : fib) {
        if (n % x == 0) {
            canUsed.push_back(x);
        }
    }
    long long res = 0;
    function <void(long long, int)> fibo = [&](long long x, int a) {
        if (n == x) {
            res++;
            return;
        }
        for (size_t i = a; i < canUsed.size(); i++) {
            long long y = canUsed[i];
            if (y <= n / x) {
                x *= y;
                fibo(x, i);
                x /= y;
            }
        }
        };
    fibo(1, 0);
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
    int t;
    cin >> t;
    while (t--)
        productOfFib();
    auto end = chrono::high_resolution_clock::now(); // Kết thúc đếm giờ
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}