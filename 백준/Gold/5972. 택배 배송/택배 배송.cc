#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 50001
#define INF 987654321
using namespace std;

int dist[MAX];
vector<pair<int, int>> graph[MAX];
void dijkstra(int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[st] = 0;
	pq.push({ dist[st],st });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;
			
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dijkstra(1);
	cout << dist[N];
	return 0;
}