#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxShell(int numShell, vector<int>& weight, int K) {
    long long maxWeight = 0;
    long long sum = 0;

    // Initialize the sum of the first K elements
    for (int i = 0; i < min(K, numShell); i++) {
        sum += weight[i];
    }
    maxWeight = sum;
    for (int i = K; i < numShell; i++) {
        sum += weight[i] - weight[i - K];
        maxWeight = max(maxWeight, sum);
    }
    return maxWeight;
}

int main() {
    int numShell, K;
    cin >> numShell;
    vector<int> weight(numShell);
    for (int i = 0; i < numShell; i++) {
        cin >> weight[i];
    }
    cin >> K;
    cout << maxShell(numShell, weight, K) << endl;
    return 0;
}