#include <iostream>
#include <queue>
using namespace std;

int T;
int N, M;


int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			q.push({ i,temp });
			pq.push(temp);
		}

		while (!q.empty()) {
			int idx = q.front().first;
			int importance = q.front().second;

			if (pq.top() > importance) {
				q.push(q.front());
				q.pop();
			}
			else {
				q.pop();
				pq.pop();
				cnt++;

				if (idx == M) {
					cout << cnt << "\n";
					break;
				}
			}
		}
	}
	return 0;
}