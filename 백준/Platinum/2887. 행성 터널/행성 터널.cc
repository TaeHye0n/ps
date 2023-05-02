#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
using namespace std;

int N; // 행성의 개수

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

	cin >> N;
	vector<pair<int, int>> coord[3];
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		coord[0].push_back({ x,i });
		coord[1].push_back({ y,i });
		coord[2].push_back({ z,i });
		parent[i] = i;
	}
	for (int i = 0; i < 3; i++) {
		sort(coord[i].begin(), coord[i].end());
	}

	vector<pair<int, pair<int, int>>> v;
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 3; j++) {
			int dist = abs(coord[j][i].first - coord[j][i + 1].first);
			int pos1 = coord[j][i].second;
			int pos2 = coord[j][i + 1].second;
			v.push_back({ dist,{pos1,pos2} });
		}
	}
	sort(v.begin(), v.end());

	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		int pos1 = v[i].second.first;
		int pos2 = v[i].second.second;
		int dist = v[i].first;
		if (find(pos1) != find(pos2)) {
			merge(pos1, pos2);
			answer += dist;
		}
	}
	cout << answer;
	return 0;
}