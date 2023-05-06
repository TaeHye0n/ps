#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001
using namespace std;

int parent[MAX];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<pair<int, pair<int, int>>> coms;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		coms.push_back({ c,{a,b} });
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	sort(coms.begin(), coms.end());
    
	int res = 0;
	for (int i = 0; i < coms.size(); i++) {
		int v1 = coms[i].second.first;
		int v2 = coms[i].second.second;
		int cost = coms[i].first;

		if (find(v1) != find(v2)) {
			merge(v1, v2);
			res += cost;
		}
	}
	cout << res;
	return 0;
}