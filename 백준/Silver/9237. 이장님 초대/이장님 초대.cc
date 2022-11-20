#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
void solve() {
    cin >> N;
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    int ans = 0;

    for (int i = 0; i < N; i++) {
        ans = max(ans, v[i] + i + 1);
    }
    cout << ans + 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}