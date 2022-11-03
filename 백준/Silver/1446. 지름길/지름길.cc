#include <iostream>
#include <vector>

#define MAX 10001
#define INF 987654321
using namespace std;

int N, D;
int dist[MAX];
vector<pair<int, int>> v[MAX];

void input() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[b].push_back({ a,c });
	}
}

void init() {
	for (int i = 1; i <= D; i++) {
		dist[i] = INF;
	}
}

void solve() {
	dist[0] = 0;
	for (int i = 1; i <= D; i++) {
		if (v[i].size() == 0) dist[i] = dist[i - 1] + 1;
		else {
			for (int j = 0; j < v[i].size(); j++) {
				dist[i] = min(dist[i], min(dist[i - 1] + 1, dist[v[i][j].first] + v[i][j].second));
			}
		}
	}
	cout << dist[D];
}

int main() {
	input();
	init();
	solve();
	return 0;
}