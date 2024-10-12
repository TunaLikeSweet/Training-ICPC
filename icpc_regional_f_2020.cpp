#include <bits/stdc++.h>
using namespace std;

int finalScore(int n, vector<char> &a) {
    vector<char> hanhAns(n, ' '); 
    for (int i = 1; i < n; i++) {
        hanhAns[i - 1] = a[i];
    }
    int score = 0;
    for (int i = 0; i < n - 1; i++) {
        if (hanhAns[i] == a[i]) {
            score++;
        }
    }
    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << finalScore(n, a) << endl;
    return 0;
}