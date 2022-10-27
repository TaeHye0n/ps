#include <iostream>
#include <queue>

#define MAX 100001
#define INF 987654321

using namespace std;

int N, K;
int ans;
int vi[MAX];
queue<int> q;
void input() {
	cin >> N >> K;
}

void solve() {
	fill_n(vi, MAX, INF);
	q.push(N);
	vi[N] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == K) {
			ans = vi[cur];
			return;
		}

		if (cur * 2 < MAX && vi[cur*2] > vi[cur]) {
			vi[cur * 2] = vi[cur];
			q.push(cur * 2);
		}

		if (cur + 1 < MAX && vi[cur+1] > vi[cur] + 1) {
			vi[cur + 1] = vi[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && vi[cur-1] > vi[cur] + 1) {
			vi[cur - 1] = vi[cur] + 1;
			q.push(cur - 1);
		}
	}
}
int main() {
	input();
	solve();
	cout << ans;
	return 0;
}