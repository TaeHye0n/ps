#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase = 0;
	cin >> testCase;

	int dp[10001][4] = { 0, };
	dp[0][1] = 1;
	dp[1][1] = 1;
	for (int i = 2; i < 10001; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if (i > 2) dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
	while (testCase--) {
		int n;
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	}
	return 0;
}