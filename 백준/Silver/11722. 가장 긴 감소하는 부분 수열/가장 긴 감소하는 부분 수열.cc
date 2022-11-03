#include <iostream>

#define MAX 1001
using namespace std;

int N;
int sequence[MAX];
int dp[MAX];
int ans;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (sequence[j] > sequence[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	cout << ans;
}

int main() {
	input();
	solve();
	return 0;
}