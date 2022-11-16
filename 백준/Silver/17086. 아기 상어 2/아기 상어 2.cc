#include <iostream>
#include <queue>

using namespace std;


int dy[8] = { 1,0,-1,0,1,1,-1,-1 };
int dx[8] = { 0,1,0,-1,1,-1,1,-1 };
int N, M;
int map[51][51];
int visited[51][51];
int answer;
queue<pair<int, int>> q;

void solve();

void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visited[i][j] = -1;
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp = map[i][j];
			cin >> temp;
			if (temp == 1) {
				visited[i][j] = 0;
				q.push({ i,j });
			}
		}
	}
}

void solve() {

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int d = 0; d < 8; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			
			if (map[ny][nx] == 0 && visited[ny][nx] == -1) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] != -1) {
				answer = max(answer, visited[i][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	input();
	solve();
	cout << answer;
	return 0;
}