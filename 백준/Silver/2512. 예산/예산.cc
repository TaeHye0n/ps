#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int budget[10001];
int maxR;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> budget[i];
		if (budget[i] > maxR) maxR = budget[i];
	}
	cin >> M;
}

void solve() {
	sort(budget, budget + N);
	long long L = 1;
	long long R = maxR;
	long long max = 0;
	while (L <= R) {
		long long res = 0;
		long long mid = (L + R) / 2;

		for (int i = 0; i < N; i++) {
			if (budget[i] > mid) res += mid;
			else res += budget[i];
		}

		if (res <= M) {
			L = mid + 1;
			if (mid > max) max = mid;
		}
		else R = mid - 1;
	}
	cout << max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}