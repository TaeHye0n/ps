#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(pair<int,pair<int, int>> p1, pair<int, pair<int, int>> p2) {
	if (p1.second.second == p2.second.second) {
		return p1.second.first < p2.second.first;
	}
	return p1.second.second > p2.second.second;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, C;
	cin >> N >> C;
	map<int, pair<int, int>> m;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (m.find(a) != m.end()) {
			m[a].second++;
		}
		else {
			m.insert({ a,{i,1} });
		}
	}

	vector<pair<int, pair<int, int>>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++) {
		while (vec[i].second.second--) {
			cout << vec[i].first << " ";
		}
	}
	return 0;
}