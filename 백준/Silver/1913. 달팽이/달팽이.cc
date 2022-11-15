#include <iostream>

using namespace std;
int N, num;
int numX, numY;
int table[1001][1001];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
bool visited[1001][1001];

void input() {
	cin >> N >> num;
}

void solve() {
	int y = 1, x = 1;
	int dir = 0;
	for (int i = N * N; i > 0; i--) {
		table[y][x] = i;
		visited[y][x] = true;
		if (num == i) {
			numX = x;
			numY = y;
		}
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 1 || nx < 1 || ny > N || nx > N || visited[ny][nx]) {
			dir = (dir + 1) % 4;
		}
		y = y + dy[dir];
		x = x + dx[dir];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}
	cout << numY << " " << numX;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}