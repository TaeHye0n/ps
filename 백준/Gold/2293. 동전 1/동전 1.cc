#include <iostream>

#define MAX 101
using namespace std;

int n, k;
int value[MAX];
int dp[10001];

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
}

void solve() {
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = value[i]; j <= k; j++) {
			dp[j] += dp[j - value[i]];
		}
	}
}

int main() {
	input();
	solve();
	cout << dp[k];
	return 0;
}