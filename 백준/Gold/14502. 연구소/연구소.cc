#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<queue>
using namespace std;

int N, M;
int map[8][8];
int copyMap[8][8];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool vi[8][8];
int answer;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

void copy(int a[8][8], int b[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void bfs() {
	int final[8][8];
	copy(final, copyMap);

	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (final[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];
			
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (final[ny][nx] == 0 ) {
				final[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (final[i][j] == 0) {
				cnt++;
			}
		}
	}

	answer = max(answer, cnt);
}

void comb(int cur) {
	if (cur == 3) {
		bfs();
		return;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copyMap[i][j] == 0) {
				copyMap[i][j] = 1;
				comb(cur + 1);
				copyMap[i][j] = 0;
			}
		}
	}

}

int main() {
	input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				copy(copyMap, map);
				copyMap[i][j] = 1;
				comb(1);
				copyMap[i][j] = 0;
			}
		}
	}
	cout << answer;
	return 0;
}
