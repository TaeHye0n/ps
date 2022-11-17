#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
int trucks[1001];
int myTime;

void input() {
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> trucks[i];
	}
}

void solve() {
	queue<int> q;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}
			if (sum + trucks[i] <= L) break;
			q.push(0);
			myTime++;
		}
		q.push(trucks[i]);
		sum += trucks[i];
		myTime++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	cout << myTime + w;
	return 0;
}