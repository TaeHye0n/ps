#include <iostream>

using namespace std;

int n;
int amount[10001];
int dp[10001];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> amount[i];
	}
}

void solve() {
	dp[0] = 0;
	amount[0] = 0;
	dp[1] = amount[1];
	dp[2] = dp[1] + amount[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + amount[i], dp[i - 3] + amount[i - 1] + amount[i]));
	}
	cout << dp[n];
}

int main() {
	input();
	solve();
	return 0;
}