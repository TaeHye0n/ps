#include <iostream>
using namespace std;

int dp[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
	}
	cout << dp[N] << "\n";

	int num = N;
	while (num >= 1) {
		cout << num << " ";
		if (num == 1) break;
		if (dp[num] == dp[num-1] + 1) {
			num -= 1;
		}
		else if (num % 2 == 0 && dp[num] == dp[num / 2] + 1) {
			num /= 2;
		}
		else if (num % 3 == 0 && dp[num] == dp[num / 3] + 1) {
			num /= 3;
		}
	}
}