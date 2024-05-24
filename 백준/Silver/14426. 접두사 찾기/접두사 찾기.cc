#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second
using namespace std;

typedef long long ll;

int n, m; //1 <= n, m <= 10000
int main() {
  
    FAST_IO;
 
    int ans = 0;

    cin >> n >> m;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        int st = 0; 
        int ed = n - 1;

        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (s < v[mid]) ed = mid - 1;
            else st = mid + 1;
            if (v[mid].substr(0, s.size()) == s) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
  
    return 0;
    
}