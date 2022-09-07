#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int vi[101][101];
int arr[101][101];
int N, M;
int answer;

void dfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	vi[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			answer = vi[y][x];
			break;
		}

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (vi[ny][nx] == 0 && arr[ny][nx] == 1) {
				q.push({ ny,nx });
				vi[ny][nx] = vi[y][x] + 1;
			}
		}
	}


}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	dfs();
	cout << answer;
	return 0;
}