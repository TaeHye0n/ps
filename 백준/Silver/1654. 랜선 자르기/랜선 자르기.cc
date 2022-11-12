#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, K;
int len[10001];
int maxR = 0;
void input() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> len[i];
		if (len[i] > maxR) {
			maxR = len[i];
		}
	}
}

void solve() {
	sort(len, len + K);
	long long max = 0;
	long long L = 1;
	long long R = maxR;
	while (L <= R) {
		long long mid = (L + R) / 2;
		long long res = 0;
		for (int i = 0; i < K; i++) {
			res += len[i] / mid;
		}

		if (res >= N) {
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