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
		dp[i] = sequence[i];
		for (int j = 0; j < i; j++) {
			if (sequence[i] > sequence[j] && dp[i] < dp[j] + sequence[i]) {
				dp[i] = dp[j] + sequence[i];
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