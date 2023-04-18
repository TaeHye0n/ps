#include <iostream>

#define MAX 101
using namespace std;

int N;
int num[MAX];
long long dp[21][MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	dp[num[1]][1] = 1;

	for (int i = 2; i <= N-1; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[j][i - 1]) {
				if (j + num[i] <= 20) dp[j + num[i]][i] += dp[j][i - 1];
				if (j - num[i] >= 0) dp[j - num[i]][i] += dp[j][i - 1];
			}
		}
	}
	cout << dp[num[N]][N - 1];

	return 0;
}