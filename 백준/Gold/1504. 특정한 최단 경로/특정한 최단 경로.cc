#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second

#define MAX 801
using namespace std;
typedef long long ll;

const int INF = 200000 * 1000 + 10;
int N, E; // 정점의 개수, 간선의 개수
vector<pair<int, int>> adj[MAX];
int dist[MAX];

void dijkstra(int start) {
	fill(dist, dist + N + 1, INF);
	dist[start] = 0;
	priority_queue < pair <int, int >, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_dist = pq.top().Y;
		int cur_node = pq.top().X;
		pq.pop();

		if (cur_dist != dist[cur_node]) continue;

		for (auto& nxt : adj[cur_node]) {
			int nxt_dist = nxt.X;
			int nxt_node = nxt.Y;
			if (dist[nxt_node] <= dist[cur_node] + nxt_dist) continue;
			dist[nxt_node] = dist[cur_node] + nxt_dist;
			pq.push({ dist[nxt_node], nxt_node });
		}
	}
}

int main() {
	FAST_IO;

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int from = 0, to = 0, cost = 0;
		cin >> from >> to >> cost;
		// 간선은 양방향
		adj[from].push_back({ to, cost });
		adj[to].push_back({ from, cost });
	}

	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;

	// 이동했던 간선도 다시 이동할 수 있다. 
	// 정점 사이에는 간선이 최대 1개 존재
	// 반드시 시작 -> v1 & v2 -> 끝을 거친 최단 거리 계산 해야한다.

	// 1. 1번 정점과 v1 or v2 정점 사이 거리 계산
	dijkstra(1);
	int start_to_v1 = dist[v1];
	int start_to_v2 = dist[v2];

	// 2. v1 정점과 v2, N번 정점 사이의 거리 계산
	dijkstra(v1);
	int v1_to_v2 = dist[v2];
	int v1_to_end = dist[N];

	// 3. v2 정점과 N번 정점 사이의 거리 계산
	dijkstra(v2);
	int v2_to_end = dist[N];

	int ans = INF;
	ans = min(ans, start_to_v1 + v1_to_v2 + v2_to_end); // start -> v1 -> v2 -> end
	ans = min(ans, start_to_v2 + v1_to_v2 + v1_to_end); // start -> v2 -> v1 -> end
	if (ans == INF || v1_to_v2 == INF) cout << -1; // v1 -> v2로 가는 방법이 없을 경우 int 자료형 overflow로 위의 min 연산에서 체크 불가
	else cout << ans;

	return 0;
}