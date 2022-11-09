#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define INF 987654321
using namespace std;

int n, m, r;
int t;
int dist[MAX];
vector<pair<int, int>> v[MAX];
vector<int> items(MAX);
int ans;
void input() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
}

void dijkstra(int st) {
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
}

int main() {
	input();
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[j] <= m) {
				sum += items[j];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}