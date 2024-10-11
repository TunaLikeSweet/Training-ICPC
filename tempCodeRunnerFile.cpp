#include <iostream>
#include <vector>
using namespace std;

struct Matrix {
    vector<vector<long long>> mat;
    int n;

    Matrix(int size) : n(size) {
        mat.resize(n, vector<long long>(n, 0));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    static Matrix identity(int size) {
        Matrix result(size);
        for (int i = 0; i < size; ++i) {
            result.mat[i][i] = 1;
        }
        return result;
    }
};

Matrix power(Matrix base, long long exp) {
    Matrix result = Matrix::identity(base.n);
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exp /= 2;
    }
    return result;
}

long long fibo(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    Matrix F(2);
    F.mat = {{1, 1}, {1, 0}};
    Matrix result = power(F, n - 1);
    return result.mat[0][0];
}

vector<long long> generateFibonacci(long long n) {
    vector<long long> fibs = {1, 1};
    while (true) {
        long long next = fibs[fibs.size() - 1] + fibs[fibs.size() - 2];
        if (next > n) break;
        fibs.push_back(next);
    }
    return fibs;
}

long long productOfFibo(long long n) {
    vector<long long> fibs = generateFibonacci(n);
    int m = fibs.size();
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j < m; ++j) {
            if (i % fibs[j] == 0) {
                dp[i] += dp[i / fibs[j]];
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
        cout << productOfFibo(n) << endl;
    }
    return 0;
}