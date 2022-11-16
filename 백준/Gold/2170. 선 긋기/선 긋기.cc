#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ans;
vector<pair<int, int>> v;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
}

void solve() {
	sort(v.begin(), v.end());
	int prevDestination = -1000000001;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first > prevDestination) {
			ans = ans + v[i].second - v[i].first;
		}
		else{
			if (prevDestination > v[i].second) continue;
			ans = ans + v[i].second - prevDestination;
		}
		prevDestination = v[i].second;

	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	return 0;
}