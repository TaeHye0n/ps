#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

queue<int> ans;
struct cmp {
	bool operator()(int &a, int &b) {
		if (abs(a) == abs(b)) return a > b;
		else return abs(a) > abs(b);
	}
};

int N;
int main() {
	cin >> N;
	priority_queue<int, vector<int>, cmp> pq;

	while (N--) {
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
	return 0;
}