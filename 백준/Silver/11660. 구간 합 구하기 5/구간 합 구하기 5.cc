#include <iostream>
#include <vector>


using namespace std;

void solve() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v[i][j];
		}
	}

	int x1, y1, x2, y2;
	while (M--) {
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
	return 0;
}