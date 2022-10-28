#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

#define MAX 1001
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N, M;
int ans = INT_MAX;
int vi[MAX][MAX][2];
int map[MAX][MAX];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}


int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},1 });
	vi[0][0][1] = 1;

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int wall = q.front().second;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			return vi[N - 1][M - 1][wall];
		}

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];
			
			if (nx < 0 || ny < 0 || ny >= N || nx >= M)continue;
			if (map[ny][nx] == 1 && wall) {
				q.push({ { ny,nx },0 });
				vi[ny][nx][wall - 1] = vi[y][x][wall] + 1;
			}
			if (map[ny][nx] == 0 && vi[ny][nx][wall] == 0) {
				q.push({ {ny,nx},wall });
				vi[ny][nx][wall] = vi[y][x][wall] + 1;
			}
		}
	}
	return -1;
}


int main() {
	input();
	cout << bfs();
	return 0;
}