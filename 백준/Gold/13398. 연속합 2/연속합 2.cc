#include <iostream>

using namespace std;

const int MAX = 1e5;
int n;
int nums[MAX+1];
int dp[MAX + 1][2];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
}

void solve() {
	dp[1][1] = nums[1];
	dp[1][0] = nums[1];
	int ans = nums[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	return 0;
}