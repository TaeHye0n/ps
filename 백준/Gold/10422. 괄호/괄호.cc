#include <iostream>

using namespace std;

typedef unsigned long long ull;
const int mod = 1e9 + 7;
ull dp[5001];

void solve() {
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i < 5001; i++) {
		for (int j = 2; j <= i; j+=2) {
			dp[i] += (dp[j - 2] * dp[i - j]) % mod;
		}
		dp[i] %= mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	solve();
	while (T--) {
		int L;
		cin >> L;

		cout << dp[L] << "\n";
	}
	return 0;
}