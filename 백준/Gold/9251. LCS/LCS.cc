#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string ans = "";
	string str1, str2;
	cin >> str1;
	cin >> str2;

	int len1 = str1.length();
	int len2 = str2.length();
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str2[j-1] == str1[i-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[len1][len2] << "\n";
}