#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	int dp[301][301] = { 0, };
	int board[301][301] = { 0, };

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i - 1][j] + board[i][j], dp[i][j - 1] + board[i][j]);
		}
	}

	cout << dp[N][M];
	return 0;
}