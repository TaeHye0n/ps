#include <iostream>
#include <queue>


using namespace std;

int N;
int ans;
queue<int> q;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
}

void solve() {
	while (1) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}

		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}
}

int main() {
	input();
	solve();
	return 0;
}