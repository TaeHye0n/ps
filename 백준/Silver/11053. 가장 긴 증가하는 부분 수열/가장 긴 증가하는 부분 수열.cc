#include <iostream>
using namespace std;

int N;
int arr[1001];
int dp[1001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}

int main() {
	input();
	solve();
	return 0;
}