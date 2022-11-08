#include<iostream>
#include<cstring>
#define MAX 501

using namespace std;

int N, M;
int map[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void input() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

int dfs(int y, int x) {
	if (y == M - 1 && x == N - 1) return 1;
	if (visited[y][x]) return dp[y][x];

	visited[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (map[y][x] > map[ny][nx]) {
			dp[y][x] += dfs(ny, nx);
		}
	}
	return dp[y][x];
}

void solve() {
	int ans = dfs(0, 0);
	cout << ans;
}

int main() {
	input();
	solve();
	return 0;
}