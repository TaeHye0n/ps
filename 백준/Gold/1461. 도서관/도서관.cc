#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
int ans;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		v.push_back(value);
	}
	v.push_back(0);
}

void solve() {
	sort(v.begin(), v.end());
	int zeroIdx = 0;
	for (int i = 0; i <= N; i++) {
		if (v[i] == 0) {
			zeroIdx = i;
			break;
		}
	}

	for (int i = 0; i < zeroIdx; i += M) {
		ans += abs(v[i] * 2);
	}
	for (int i = N; i > zeroIdx; i -= M) {
		ans += v[i] * 2;
	}
	ans -= max(abs(v[0]), abs(v[N]));
	cout << ans;
}
int main() {
	input();
	solve();
	return 0;
}