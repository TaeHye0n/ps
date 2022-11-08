#include <iostream>

using namespace std;

int N;
int dp[1001];

void input() {
	cin >> N;
}

void solve() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= N; i++) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 1] + 1);
	}
	if (dp[N] % 2) cout << "SK";
	else cout << "CY";
}

int main() {
	input();
	solve();
	return 0;
}