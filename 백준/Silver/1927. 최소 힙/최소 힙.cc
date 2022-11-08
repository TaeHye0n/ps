#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> ans;

void solve() {
	for (int i = 1; i <= N; i++) {
		int value;
		cin >> value;
		if (value == 0) {
			if (pq.empty()) ans.push(0);
			else {
				ans.push(pq.top());
				pq.pop();
			}
		}
		else pq.push(value);
	}

	while (!ans.empty()) {
		cout << ans.front() << "\n";
		ans.pop();
	}
}

int main() {
	cin >> N;
	solve();
	return 0;
}