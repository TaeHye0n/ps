#include <iostream>

using namespace std;

int N;
int price[1001];
int dp[1001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}
}

void solve() {
	dp[0] = 0;
	price[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + price[j]);
		}
	}
	cout << dp[N];
}

int main() {
	input();
	solve();
	return 0;
}