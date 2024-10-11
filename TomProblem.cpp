#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

void processCommand(int numCommands, vector<string>& command) {
    stack<int> dile1, dile2;
    for (const string& cmd : command) {
        if (cmd == "DROP") {
            int m = stoi(cmd.substr(5));
            cout << "DROP 2" << m << endl;
            for (int i = 0; i < m; i++) {
                dile2.push(dile1.top());
                dile1.pop();
            }
        } else if (cmd == "TAKE") {
            int m = stoi(cmd.substr(5));
            while (m > 0) {
                if (dile1.empty()) {
                    int n = dile2.size();
                    while (!dile2.empty()) {
                        dile1.push(dile2.top());
                        dile2.pop();
                    }
                }
                int takeCount = min(m, static_cast<int>(dile1.size()));
                cout << "TAKE 1 " << takeCount << endl;
                for (int i = 0; i < takeCount; i++)
                    dile1.pop();
                m -= takeCount;
            }
        }
    }
}

int main() {
    int numCommands;
    cin >> numCommands;
    vector<string> command(numCommands);
    for (int i = 0; i < numCommands; i++) {
        cin >> command[i];
    }
    processCommand(numCommands, command);
    return 0;
}