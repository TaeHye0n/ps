#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX 1000001

using namespace std;
typedef long long ll;

int n;
int pos[MAX];
vector<int> dp;
vector<int> record;
vector<pair<int, int>> v;

int main() {
    FAST_IO;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());
    dp.push_back(v[0].second);

    for (int i = 1; i < n; i++) {
        if (dp.back() < v[i].second) {
            dp.push_back(v[i].second);
            pos[i] = dp.size() - 1;
        } else {
            auto iter = lower_bound(dp.begin(), dp.end(), v[i].second);
            *iter = v[i].second;
            pos[i] = iter - dp.begin();
        }
    }

    int cnt = dp.size();
    cout << n - cnt << endl;
    cnt--;
    for (int i = n - 1; i >= 0; i--) {
        if (pos[i] == cnt) {
            cnt--;
            continue;
        }
        record.push_back(v[i].first);
    }

    for (int i = record.size() - 1; i >= 0; i--) {
        cout << record[i] << endl;
    }


    return 0;
}

