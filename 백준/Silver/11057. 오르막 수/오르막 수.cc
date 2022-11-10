#include <iostream>

using namespace std;

const int mod = 1e4 + 7;
int N;
int dp[1001][11];

int main() {
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += (dp[i - 1][k]) % mod;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[N][i]) % mod;
	}
	cout << ans;
	return 0;
}