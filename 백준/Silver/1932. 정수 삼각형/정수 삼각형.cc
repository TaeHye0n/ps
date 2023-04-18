#include <iostream>
#include <vector>

#define MAX 501
using namespace std;

int n;
int tri[MAX][MAX];
int dp[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> tri[i][j];
		}
	}
	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + tri[i][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tri[i][j];
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(dp[n - 1][i], res);
	}
	cout << res;
	return 0;
}