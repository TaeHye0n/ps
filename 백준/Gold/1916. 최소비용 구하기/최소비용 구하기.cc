#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001
#define INF 987654321

using namespace std;

int N, M;
vector<pair<int, int>> v[MAX];
int dist[MAX];
int dep, arri;

void input() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}
	cin >> dep >> arri;
}

void solve(int dep) {
	priority_queue<pair<int, int>> pq;
	dist[dep] = 0;
	pq.push({ 0, dep });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;

			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	input();
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	solve(dep);
	cout << dist[arri];
	return 0;
}