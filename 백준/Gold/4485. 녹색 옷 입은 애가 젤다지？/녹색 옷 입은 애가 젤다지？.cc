#include <iostream>
#include <queue>
#include <cstring>

#define MAX 126
#define INF 987654321
using namespace std;

int N;
int cave[MAX][MAX] = { 0, };
int ans;
int Dist[MAX][MAX] = {0,};
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void dijkstra();

void solve() {
	int idx = 1;
	while (1) {
		cin >> N;
		if (N == 0) break;
		memset(cave, 0, sizeof(cave));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> cave[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Dist[i][j] = INF;
			}
		}
		dijkstra();
		cout << "Problem " << idx << ": " << ans << "\n";
		idx++;
	}
}

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -cave[0][0], {0,0} });
	Dist[0][0] = cave[0][0];

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			int nCost = cost + cave[ny][nx];
			if (Dist[ny][nx] > nCost) {
				Dist[ny][nx] = nCost;
				pq.push({ -Dist[ny][nx],{ny,nx} });
			}
		}
	}
	ans = Dist[N - 1][N - 1];
}

int main() {
	solve();
	return 0;
}