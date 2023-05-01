#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 101
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

	int n;
	cin >> n;
	vector<pair<double, double>> pos;
	for (int i = 1; i <= n; i++) {
		double a, b;
		cin >> a >> b;
		pos.push_back({ a,b });
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	vector<pair<double, pair<int, int>>> v;
	for (int i = 0; i < n; i++) {
		double x1 = pos[i].first;
		double y1 = pos[i].second;
		for (int j = i + 1; j < n; j++) {
			double x2 = pos[j].first;
			double y2 = pos[j].second;
			double dist1 = pow(x2 - x1, 2);
			double dist2 = pow(y2 - y1, 2);
			double dist = sqrt(dist1 + dist2);
			v.push_back({ dist,{i + 1,j + 1} });
		}
	}
	sort(v.begin(), v.end());
	double ans = 0;

	for (int i = 0; i < v.size(); i++) {
		int prev = v[i].second.first;
		int next = v[i].second.second;

		if (find(prev) != find(next)) {
			Union(prev, next);
			ans += v[i].first;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}