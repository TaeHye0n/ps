#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int dp[16][16] = { 0, };

	int N, M;
	cin >> N >> M;
	int circle = 0;
	pair<int, int> dest = { 0,0 };
	dp[1][1] = 1;
	cin >> circle;
	
	if (circle != 0) {
		dest = { 1+ circle / M, circle % M };
		for (int i = 1; i <= dest.first; i++) {
			for (int j = 1; j <= dest.second; j++) {
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			}
		}
		int route1 = dp[dest.first][dest.second];
		dp[dest.first][dest.second] = 1;
		for (int i = dest.first; i <= N; i++) {
			for (int j = dest.second; j <= M; j++) {
				if (i == dest.first & j == dest.second) continue;
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			}
		}

		cout << dp[N][M] * route1;
	}
	else {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[N][M];
	}

	
	return 0;
}