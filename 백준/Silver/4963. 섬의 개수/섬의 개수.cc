#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

bool visited[51][51];
int dy[8] = { 1,0,-1,0,1,1,-1,-1 };
int dx[8] = { 0,1,0,-1,1,-1,1,-1 };
queue<pair<int, int>> q;
int map[51][51];
int w, h;

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int dir = 0; dir < 8; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

			if (!visited[ny][nx] && map[ny][nx] == 1) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		int ans = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j] == 1) {
					q.push({ i,j });
					visited[i][j] = true;
					bfs();
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}