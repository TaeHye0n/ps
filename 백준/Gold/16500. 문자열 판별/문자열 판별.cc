#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define first Y
#define second X
#define endl "\n"

using namespace std;
typedef long long ll;
bool dp[101];

int main() {
    FAST_IO;

    string s;
    cin >> s;
    int size = s.length();
    dp[size] = true;
    
    int n = 0;
    cin >> n;

    vector<string> v;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    for (int i = size; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (v[j].length() + i > size) continue;
            if (s.find(v[j], i) != i) continue;
            dp[i] = dp[i] || dp[v[j].length() + i];
        }
    }
    cout << dp[0];
    return 0;
}

