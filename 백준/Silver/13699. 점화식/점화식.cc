#include <iostream>
#include <vector>

using namespace std;

int n;

void solve() {
    cin >> n;
    vector<long long> dp(n+1,0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    cout << dp[n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}