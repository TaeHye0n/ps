#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int ans = 1;
vector<pair<int, int>> v;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int from = 0, to = 0;
		cin >> from >> to;
		v.push_back({ from,to });
	}
}

void solve() {
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
			ans++;
		}
	}
}

int main() {
	input();
	solve();
	cout << ans;
	return 0;
}