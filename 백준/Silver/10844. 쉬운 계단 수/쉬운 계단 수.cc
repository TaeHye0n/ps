#include <iostream>

using namespace std;

const int mod = 1e9;

int N;
int dp[101][10];

void solve() {
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans+dp[N][i]) % mod;
	}
	cout << ans;
}

int main() {
	cin >> N;
	solve();
	return 0;
}