#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int keyStone(int numPillars, vector<int> &heightPillar) {
    auto analyze = [&](vector<int> &a) -> vector<int> {
        int n = a.size();
        vector<int> dp(n);
        dp[0] = min(1, a[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[i - 1] + 1, a[i]);
        }
        return dp;
    };
    vector<int> left = analyze(heightPillar);
    reverse(heightPillar.begin(), heightPillar.end());
    vector<int> right = analyze(heightPillar);
    reverse(right.begin(), right.end());
    int res = 0;
    for (int i = 0; i < numPillars; i++) {
        res = max(res, min(left[i], right[i]));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numPillars;
    cin >> numPillars;
    vector<int> heightPillar(numPillars);
    for (int i = 0; i < numPillars; i++) {
        cin >> heightPillar[i];
    }
    cout << keyStone(numPillars, heightPillar);
    return 0;
}