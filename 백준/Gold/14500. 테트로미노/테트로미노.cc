#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int paper[501][501];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int visited[501][501];
int ans;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}
}
void dfs(int y, int x, int cnt, int score) {
	if (cnt == 4) {
		ans = max(ans, score);
		return;
	}

	for (int w = 0; w < 4; w++) {
		int ny = y + dy[w];
		int nx = x + dx[w];

		if (ny < 0 || nx < 0 || ny > N || nx > M) continue;
		if (visited[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, cnt + 1, score + paper[ny][nx]);
		visited[ny][nx] = 0;
	}

	
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			dfs(i, j, 1, paper[i][j]);
			visited[i][j] = 0;
			// ㅏ,ㅓ, ㅗ, ㅜ 

			if (j + 1 < M && i + 2 < N) { // ㅏ
				ans = max(ans, (paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j + 1]));
			}
			if (j - 1 >= 0 && i + 2 < N) { // ㅓ
				ans = max(ans, (paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j - 1]));
			}
			if (j + 2 < M && i - 1 >= 0) { // ㅗ
				ans = max(ans, (paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i - 1][j + 1]));
			}
			if (j + 2 < M && i + 1 < N) { // ㅜ
				ans = max(ans, (paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1]));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	input();
	solve();
	cout << ans;
	return 0;
}