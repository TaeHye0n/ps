#include <iostream>
#include <string>
#include <map>

using namespace std;

string s;
map<char, int> m;

void input() {
    cin >> s;
}

void solve() {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '9') {
            m['6']++;
        }
        else m[s[i]]++;
    }

    int max = 0;
    char temp = ' ';
    bool oversix = false;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > max || (iter->first > '6' && iter->second ==max)) {
            max = iter->second;
            temp = iter->first;
        }
    }

    if (temp == '6') {
        cout << (max + 1) / 2;
    }
    else cout << max;
}
int main() {
    input();
    solve();
    return 0;
}