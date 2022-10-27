#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1010
#define INF 987654321

using namespace std;


int N, M, X;
int ans;
int Dist[MAX], Res[MAX];
vector<pair<int, int>> v[MAX];

void input() {
	cin >> N >> M >> X;
	int from, to, dist = 0;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> dist;
		v[from].push_back({ to,dist });
	}
}

void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	Dist[start] = 0;
	pq.push({ 0,start });
	
	while (!pq.empty()) {
		int dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ndist = v[cur][i].second;

			if (Dist[next] > dist + ndist) {
				Dist[next] = dist + ndist;
				pq.push({ Dist[next], next });
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Dist[j] = INF;
		}
		dijkstra(i);
		Res[i] = Dist[X];
	}
	for (int j = 1; j <= N; j++) {
		Dist[j] = INF;
	}
	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		Res[i] += Dist[i];
	}
	ans = *max_element(Res+1, Res + N+1);
}

int main() {
	input();
	solve();
	cout << ans;
	return 0;
}