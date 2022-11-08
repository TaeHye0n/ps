#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n;
stack<int> s;
queue<int> q;
queue<char> q2;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}
}

void solve() {
	int st = 1;
	s.push(st);
	q2.push('+');
	st = 2;
	bool flag = false;
	while (!q.empty()) {
		if (!s.empty() && s.top() == q.front()) {
			s.pop();
			q.pop();
			q2.push('-');
		}
		else {
			s.push(st);
			st++;
			q2.push('+');
		}
		if (st > n+1) {
			flag = true;
			break;
		}
	}
	if (flag) cout << "NO";
	else {
		while (!q2.empty()) {
			cout << q2.front() << "\n";
			q2.pop();
		}
	}
}

int main() {
	input();
	solve();
	return 0;
}