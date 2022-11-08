#include <iostream>

#define INF 987654321
using namespace std;

int n;
int dp[1000001];
void input() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		dp[i] = INF;
	}
}

void solve() {
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (i + 1 > n) continue;
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i *2 > n) continue;
		dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		if (i *3 > n) continue;
		dp[i * 3] = min(dp[i * 3], dp[i] + 1);
	}
	cout << dp[n];
}


int main() {
	input();
	solve();
	return 0;
}