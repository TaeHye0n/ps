#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int T;
int N;
int h[10001];

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> h[i];
		}
		sort(h, h + N, greater<int>());
		deque<int> dq;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) dq.push_front(h[i]);
			else dq.push_back(h[i]);
		}

		int ans = abs(dq.front() - dq.back());
		for (int i = 0; i < dq.size()-1; i++) {
			ans = max(ans, abs(dq[i] - dq[i + 1]));
		}
		cout << ans << "\n";
	}
	return 0;
}