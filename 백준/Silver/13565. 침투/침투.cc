#include <iostream>
#include <cstdio>
#include <queue>

#define MAX 1000
using namespace std;

const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,1,0,-1 };

int map[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int M, N;

queue<pair<int, int>> q;

void input() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}

string solve() {
	for (int i = 0; i < N; i++) {
		if (map[0][i] == 0) {
			q.push({ 0,i });
			visited[0][i] = true;
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;

			if (!visited[ny][nx] && map[ny][nx] == 0) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
	bool canPercolate = false;
	for (int i = 0; i < N; i++) {
		if (map[M - 1][i] == 0 && visited[M - 1][i]) {
			canPercolate = true;
			break;
		}
	}
	if (canPercolate) return "YES";
	return "NO";
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	input();
	cout << solve();
	return 0;
}