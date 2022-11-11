#include <iostream>

using namespace std;

int N;
int map[101][101];
long long dp[101][101];
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
}

void solve() {
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == 0 || (i == N && j == N))continue;
			int jump = map[i][j];
			if (i + jump <= N) {
				dp[i + jump][j] += dp[i][j];
			}
			if (j + jump <= N) {
				dp[i][j + jump] += dp[i][j];
			}
		}
	}
}

int main() {
	input();
	solve();
	cout << dp[N][N];
	return 0;
}