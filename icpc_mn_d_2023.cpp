#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int get_n_dangerous(const vector<vector<int>>& graph, int weight) {
    int n = graph.size();
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = graph[i][j] < weight;
        }
    }
    vector<vector<int>> dist(n, vector<int>(n, 1e9 + 7));
    dist[0][0] = cost[0][0];
    queue<pair<int, int>> q;
    q.push({0, 0});
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = current.first + directions[i][0];
            int ny = current.second + directions[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (dist[nx][ny] > dist[current.first][current.second] + cost[nx][ny]) {
                    dist[nx][ny] = dist[current.first][current.second] + cost[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
    }
    return dist[n - 1][n - 1];
}

bool max_weight(const vector<vector<int>>& graph, int weight) {
    int n = graph.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = current.first + directions[i][0];
            int ny = current.second + directions[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && graph[nx][ny] >= weight) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return visited[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    if (t == 1) {
        int n, G;
        cin >> n >> G;
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        cout << get_n_dangerous(graph, G) << endl;
    } else if (t == 2) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        int low = 0, high = 1e4, MAX = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (max_weight(graph, mid)) {
                MAX = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << MAX << endl;
    }
    return 0;
}