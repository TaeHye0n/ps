#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;

int dp[2][MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> dp[i][j];
			}
		}
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + dp[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + dp[1][i];
		}
		int res = max(dp[0][n], dp[1][n]);
		cout << res << "\n";
	}
	
	return 0;
}