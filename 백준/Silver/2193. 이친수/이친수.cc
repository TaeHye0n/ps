#include <iostream>

using namespace std;

int N;
long long dp[91];

void input() {
	cin >> N;
}

void solve() {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N];
}

int main() {
	input();
	solve();
	return 0;
}