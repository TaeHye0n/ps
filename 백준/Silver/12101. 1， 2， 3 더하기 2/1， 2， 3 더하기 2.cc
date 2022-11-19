#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<string> v;

void input() {
	cin >> n >> k;
}

void dfs(string s, int sum) {
	if (sum >= n) {
		if (sum == n) v.push_back(s.substr(1));
		return;
	}
	dfs(s + "+1", sum + 1);
	dfs(s + "+2", sum + 2);
	dfs(s + "+3", sum + 3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	dfs("", 0);
	sort(v.begin(), v.end());
	if (v.size() >= k) cout << v[k - 1];
	else cout << -1;
	return 0;
}