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
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		ans += v[i].second;

		if (pq.size() > v[i].first) {
			ans -= pq.top();
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