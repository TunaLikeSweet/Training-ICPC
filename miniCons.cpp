#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

void solution(long long n, long long a, long long b, long long c) {
    long long count_ab = (n % lcm(a, b) == 0) ? n / lcm(a, b) : 0;
    long long count_bc = (n % lcm(b, c) == 0) ? n / lcm(b, c) : 0;
    long long count_ac = (n % lcm(a, c) == 0) ? n / lcm(a, c) : 0;
    long long count_abc = (n % lcm(lcm(a, b), c) == 0) ? n / lcm(lcm(a, b), c) : 0;

    long long ans = count_ab + count_bc + count_ac - 2 * count_abc;
    cout << ans << endl;
}

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    solution(n, a, b, c);
    return 0;
}