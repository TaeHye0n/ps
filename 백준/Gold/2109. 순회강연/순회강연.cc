#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;
int ans;
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
}

void solve() {
	priority_queue<int> pq;
	for (int i = 10000; i > 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i == v[j].first) pq.push(v[j].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
}

int main() {
	input();
	solve();
	cout << ans;
	return 0;
}