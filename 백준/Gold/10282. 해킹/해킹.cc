#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		int ans = 0, cnt = 0;
		int n, d, c;
		cin >> n >> d >> c;

		int dist[10001] = { 0, };
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
		}

		vector<pair<int, int>> graph[10001];
		for (int i = 0; i < d; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[b].push_back({ a,c });
		}

		dist[c] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>,
			greater<pair<int, int>>> pq;

		pq.push({ 0, c });
		while (!pq.empty()) {
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (cost > dist[cur]) continue;
			ans = cost;
			cnt++;

			for (int i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i].first;
				int ncost = graph[cur][i].second;
			
				if (dist[next] > ncost + cost) {
					dist[next] = ncost + cost;
					pq.push({ ncost + cost,next });
				}
			}
		}
		cout << cnt << " " << ans << "\n";
	}
	return 0;
}