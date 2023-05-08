#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	int arr[1001][3] = { 0, };
	int dp[1001][3] = { 0, };
	cin >> N;
	int ans = INF;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int color = 0; color <= 2; color++) {
		for (int i = 0; i <= 2; i++) {
			if (i == color) {
				dp[1][i] = arr[1][i];
			}
			else dp[1][i] = INF;
		}

		for (int i = 2; i <= N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}

		for (int i = 0; i <= 2; i++) {
			if (i == color) continue;
			ans = min(ans, dp[N][i]);
		}
	}

	cout << ans;
	return 0;
}