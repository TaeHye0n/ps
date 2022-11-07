#include <iostream>
#include <cstring>
#include <climits>

#define MAX 501
using namespace std;

int T, K;
int cost[MAX];
int sum[MAX];
int dp[MAX][MAX];



int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int i = 1; i <= K; i++) {
			for (int j = 1; i + j <= K; j++) {
				dp[j][i + j] = INT_MAX;
				for (int k = j; k < i + j; k++) {
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][K] << "\n";
	}
	return 0;
}