#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define MAX 20001

using namespace std;

const int INF = INT_MAX;

int V, E;
int st;
vector<pair<int, int>> v[MAX];
int dist[MAX];

void input() {
	cin >> V >> E;
	cin >> st;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
}

void init() {
	for (int i = 0; i < MAX; i++) {
		dist[i] = INF;
	}
}

void solve(int st) {
	init();
	dist[st] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,st });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int ncost = v[cur][i].second;
			int next = v[cur][i].first;

			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next],next });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF) cout << dist[i] << "\n";
		else cout << "INF\n";
	}
}

int main() {
	input();
	solve(st);
	return 0;
}