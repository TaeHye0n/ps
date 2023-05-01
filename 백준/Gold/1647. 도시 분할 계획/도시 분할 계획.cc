#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
using namespace std;

int parent[MAX];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
	}
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	
	sort(v.begin(), v.end());
	
	int res = 0;
	int maxCost = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (find(v[i].second.first) != find(v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			maxCost = max(maxCost, v[i].first);
			res += v[i].first;
		}
	}
	res -= maxCost;
	cout << res;
	return 0;
}