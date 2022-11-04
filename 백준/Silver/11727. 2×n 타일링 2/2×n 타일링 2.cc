#include <iostream>

#define MAX 1001
using namespace std;

int n;
int dp[1001];
void input() {
	cin >> n;
}

void solve() {
	
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
}

int main() {
	input();
	solve();
	cout << dp[n];
	return 0;
}