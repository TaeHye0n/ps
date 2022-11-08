#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> pq;
queue<int> ans;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (pq.empty()) ans.push(0);
			else {
				ans.push(pq.top());
				pq.pop();
			}
		}
		else pq.push(temp);
	}
	
	while (!ans.empty()) {
		cout << ans.front() << "\n";
		ans.pop();
	}
}

int main() {
	solve();
	return 0;
}