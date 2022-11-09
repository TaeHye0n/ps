#include <iostream>

#define MOD 9901
using namespace std;

int N;
int dp[100001][3];

void input() {
	cin >> N;
}

void solve() {
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}
	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;
}

int main() {
	input();
	solve();
	return 0;
}