#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

typedef long long ll;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}
int main() {
	FAST_IO;

	int n; cin >> n;

	vector<pair<int, int>> v; // (걸리는 시간, 끝내야하는 시간)
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), cmp);

	int t = v[0].second - v[0].first;
	for (int i = 1; i < v.size(); i++) {
		if (t <= v[i].second) {
			t -= v[i].first;
		}
		else {
			t = v[i].second - v[i].first;
		}
	}
	if (t < 0) cout << -1;
	else cout << t;
	return 0;
}