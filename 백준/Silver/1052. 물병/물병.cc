#include <iostream>

using namespace std;

int N, K; // N : 물병의 개수, K : 한번에 옮길 수 있는 물병 수

void input() {
	cin >> N >> K;
}

void solve() {
	input();
	int ans = 0;
	
	if (K >= N) {
		cout << 0;
		return;
	}

	while (1) {
		int cnt = 0;
		int temp = N;
		while (temp > 0) {
			if (temp % 2 == 0) temp /= 2;
			else {
				temp /= 2;
				cnt++;
			}
		}
		if (K >= cnt) break;
		N++;
		ans++;
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	return 0;
}