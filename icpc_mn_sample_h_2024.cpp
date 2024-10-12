#include <bits/stdc++.h>
using namespace std;

string multiplyString(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j] += sum / 10;
            res[i + j + 1] = sum % 10;
        }
    }
    string result;
    for (int num : res) {
        if (!(result.empty() && num == 0)) {
            result.push_back(num + '0');
        }
    }
    return result.empty() ? "0" : result;
}

string divideString(const string& num, int divisor) {
    string result;
    int idx = 0;
    int temp = num[idx] - '0';
    while (temp < divisor) {
        temp = temp * 10 + (num[++idx] - '0');
    }
    while (num.size() > idx) {
        result += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + num[++idx] - '0';
    }
    if (result.length() == 0) {
        return "0";
    }
    return result;
}

string addString(string a, string b) {
    int n = a.size();
    int m = b.size();
    int carry = 0;
    string result;
    for (int i = n - 1, j = m - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
        }
        if (j >= 0) {
            sum += b[j] - '0';
        }
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}

// n * (n + 1) * (2n + 1) / 6
string fomular(string n) {
    string a = multiplyString(n, addString(n, "1"));
    string b = multiplyString(a, addString(multiplyString(n, "2"), "1"));
    return divideString(b, 6);
}

long long sumOfSquares(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long A, B, M;
    cin >> A >> B >> M;

    long long sumB = sumOfSquares(B);
    long long sumA = sumOfSquares(A - 1);
    long long result = (sumB - sumA) % M;

    cout << result << endl;

    return 0;
}