#include <iostream>

using namespace std;

const int mod = 1e9 + 9;

int T;
int n;
int dp[100001][4];
void solve() {
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
	}
	
}

int main() {
	cin >> T;
	solve();
	while (T--) {
		cin >> n;
		cout << ((long long)dp[n][1] + dp[n][2] + dp[n][3]) % mod << "\n";
	}
	return 0;
}