#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(71, 0);
    vec[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> temp = vec;
        for (int j = 0; j < 71; j++) {
            int y = __gcd(j, x);
            temp[y] = (temp[y] + vec[j]) % MOD;
        }
        swap(vec, temp);
    }
    int ans = 0;
    for (int i = 0; i < 71; i++) {
        ans = (ans + 1LL * i * vec[i]) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}