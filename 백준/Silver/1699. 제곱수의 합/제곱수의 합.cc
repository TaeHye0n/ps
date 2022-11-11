#include <iostream>

using namespace std;

const int MAX = 1e5;
int N;
int dp[MAX+1];

void input() {
	cin >> N;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		dp[i] = MAX + 1;
	}

	for (int i = 1; i * i <= N; i++) {
		for (int j = i*i; j <= N; j++) {
			dp[j] = min(dp[j], dp[j - i*i]+1);
		}
	}
	cout << dp[N];
}

int main() {
	input();
	solve();
	return 0;
}