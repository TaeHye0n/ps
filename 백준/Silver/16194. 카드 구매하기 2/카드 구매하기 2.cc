#include <iostream>

using namespace std;

int N;
int card[1001];
int dp[1001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
		dp[i] = card[i];
	}
}

void solve() {
	dp[0] = 0;
	dp[1] = card[1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + card[j]);
		}
	}
	cout << dp[N];
}

int main() {
	input();
	solve();
	return 0;
}