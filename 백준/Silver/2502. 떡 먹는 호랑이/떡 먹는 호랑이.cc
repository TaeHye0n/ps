#include <iostream>
#include <vector>

using namespace std;

int D; // 넘어온 날
int K; // D날 준 떡의 개수

int dp[31];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> D >> K;
	dp[D] = K;

	for (int i = 1; i <= K; i++) {
		bool flag = false;
		dp[1] = i;
		for (int j = i + 1; j <= K; j++) {
			dp[2] = j;
			for (int h = 3; h <= D; h++) {
				dp[h] = dp[h - 1] + dp[h - 2];
			}
			if (dp[D] == K) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	cout << dp[1] << "\n";
	cout << dp[2];
	return 0;
}