#include <bits/stdc++.h>
using namespace std;

void welcomeMessage() {
    auto split = [&](string s) -> set<string>{
        set<string> wordSet;
        string word;
        istringstream iss(s);
        while (iss >> word) {
            wordSet.insert(word);
        }
        return wordSet;
        };
    string s;
    string t;
    getline(cin, t);
    while (getline(cin, s))
        t += " " + s;
    vector<string> keys = { "Welcome", "Hue", "University", "of", "Sciences" };
    set<string> wordSet = split(t);
    for (string word : keys) {
        if (wordSet.find(word) != wordSet.end()) {
            wordSet.erase(word);
        } else {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    welcomeMessage();
    return 0;
}