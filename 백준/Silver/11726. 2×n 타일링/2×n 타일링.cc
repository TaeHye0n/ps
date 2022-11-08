#include<iostream>

#define MAX 1001
using namespace std;

int N;
int dp[MAX];

void input() {
	cin >> N;
}

void solve() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
}

int main() {
	input();
	solve();
	cout << dp[N];
	return 0;
}