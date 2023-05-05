#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 801
#define INF 987654321
using namespace std;

int N, E;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
int V1, V2;
void dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0,start });
	
	while (!pq.empty()) {
		int curDist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (curDist > dist[cur]) continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nDist = graph[cur][i].second;
			if (dist[next] > curDist + nDist) {
				dist[next] = curDist + nDist;
				pq.push({ curDist + nDist, next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> V1 >> V2;

	int stToV1 = 0, stToV2 = 0;
	int v1ToV2 = 0;
	int v1ToN = 0, v2ToN = 0;
	
	dijkstra(1);
	stToV1 = dist[V1];
	stToV2 = dist[V2];

	dijkstra(V1);
	v1ToV2 = dist[V2];
	v1ToN = dist[N];

	dijkstra(V2);
	v2ToN = dist[N];

	int ans = INF;
	ans = min(ans, stToV1 + v1ToV2 + v2ToN);
	ans = min(ans, stToV2 + v1ToV2 + v1ToN);
	if (ans == INF || v1ToV2 == INF) cout << -1;
	else cout << ans;
	return 0;
}