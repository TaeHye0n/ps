#include<iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int N, Q;
int maxCluster;
int remain;
int map[65][65];
int copyMap[65][65];
bool melt[65][65];
bool vi[65][65];
int L[1001];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void input() {
	cin >> N;
	cin >> Q;
	N = pow(2, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];	
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> L[i];
	}
}


void rotateMap(int x, int y, int L) {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			copyMap[i][j] = map[y + L - 1 - j][x + i];
		}
	}
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			map[y + i][x + j] = copyMap[i][j];
		}
	}
}

void solve(int L) {
	L = pow(2, L);

	for (int i = 0; i < N; i += L) {
		for (int j = 0; j < N; j += L) {
			rotateMap(i, j, L);
		}
	}

	memset(melt, false, sizeof(melt));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) continue;
			int cnt = 0;
			for (int w = 0; w < 4; w++) {
				int ny = i + dy[w];
				int nx = j + dx[w];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (map[ny][nx] > 0) cnt++;
			}
			if (cnt < 3) melt[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (melt[i][j]) {
				map[i][j]--;
			}
		}
	}
}

void getRemain() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) remain += map[i][j];
		}
	}
}
void bfs(int y, int x) {
	int size = 0;
	queue < pair<int, int>> q;
	q.push({ y,x });
	vi[y][x] = false;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (!vi[ny][nx] && map[ny][nx] > 0) {
				q.push({ ny,nx });
				vi[ny][nx] = true;
				size++;
			}
		}
	}
	maxCluster = max(size, maxCluster);
}

void getMaxCluster() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 0) {
				bfs(i, j);
				memset(vi, false, sizeof(vi));
			}
		}
	}
}



int main() {
	input();
	for (int i = 0; i < Q; i++) {
		solve(L[i]);
	}
	getRemain();
	getMaxCluster();
	cout << remain << "\n" << maxCluster;
	return 0;
}