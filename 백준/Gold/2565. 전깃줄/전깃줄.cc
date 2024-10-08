#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second

using namespace std;
typedef long long ll;



int main() {
	FAST_IO;
	int n = 0;
	cin >> n;

	vector<pair<int, int>> line;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({ a, b });
	}

	sort(line.begin(), line.end());
	int dp[101] = { 0, };
	int max_lis = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (line[j].second < line[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		max_lis = max(max_lis, dp[i]);
	}

	cout << n - max_lis;
	return 0;
}