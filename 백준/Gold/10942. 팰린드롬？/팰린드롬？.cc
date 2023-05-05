#include <iostream>

using namespace std;

int N; // 수열의 크기
int M; // 질문의 개수

int nums[2001];
bool dp[2001][2001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		dp[i][i] = true;
		if (i > 1 && nums[i - 1] == nums[i]) {
			dp[i - 1][i] = true;
		}
	}
	
	for (int i = 2; i <= N; i++) {
		for (int j = 1; i + j <= N; j++) {
			if (nums[j] == nums[i + j] && dp[j + 1][i + j - 1]) {
				dp[j][i + j] = true;
			}
		}
	}

	cin >> M;
	
	while (M--) {
		int a, b;
		cin >> a >> b;
		if (dp[a][b]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}