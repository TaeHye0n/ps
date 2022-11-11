#include <iostream>

using namespace std;

int N, M;
int maze[1001][1001];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			maze[i][j] += max(maze[i - 1][j], max(maze[i][j - 1], maze[i - 1][j - 1]));
		}
	}
}

int main() {
	input();
	solve();
	cout << maze[N][M];
	return 0;
}