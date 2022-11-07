#include <iostream>

using namespace std;

int T, n;
int dp[11];

void solve() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
}

int main() {
	int cnt = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		if (cnt == 0) solve();
		cnt++;
		cout << dp[n] << "\n";
	}
	return 0;
}