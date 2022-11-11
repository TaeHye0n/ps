#include <iostream>

using namespace std;

const int MAX = 1e5;
int n;
int sequence[MAX];
int dp[MAX];
int ans;
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sequence[i];
	}
}

void solve() {
	ans = sequence[1];
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + sequence[i], sequence[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}

int main() {
	input();
	solve();
	return 0;
}