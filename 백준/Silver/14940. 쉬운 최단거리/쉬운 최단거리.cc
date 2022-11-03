#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX];

queue<pair<int, int>> q;

void init();

void input() {
	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q.push({ i,j });
				visited[i][j] = 0;
			}
			if (map[i][j] == 0) {
				visited[i][j] = 0;
			}
		}
	}
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = -1;
		}
	}
}

void solve() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (visited[ny][nx] == -1 && map[ny][nx] == 1) {
				q.push({ ny,nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << "\n";
	}
}

int main() {
	input();
	solve();
	return 0;
}