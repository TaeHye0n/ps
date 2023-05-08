#include <iostream>
#include <queue>

#define MAX 301
using namespace std;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };
int N, M;

bool visited[MAX][MAX];
int board[MAX][MAX];
bool allMelted;
bool isEnd() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0 && visited[i][j] == false) {
				cnt++;
				queue<pair<int, int>>q;
				q.push({ i,j });
				visited[i][j] = true;
				
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int w = 0; w < 4; w++) {
						int ny = y + dy[w];
						int nx = x + dx[w];

						if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

						if (board[ny][nx] > 0 && !visited[ny][nx]) {
							q.push({ ny,nx });
							visited[ny][nx] = true;
						}
					}
				}
			}
		}
	}
	if (cnt >= 2) return true;
	if (cnt == 0) {
		allMelted = true;
		return true;
	}
	return false;
}

void melt() {
	int temp[MAX][MAX] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0) {
				int cnt = 0;
				for (int w = 0; w < 4; w++) {
					int ny = i + dy[w];
					int nx = j + dx[w];

					if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

					if (board[ny][nx] <= 0) cnt++;
				}
				temp[i][j] -= cnt;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = temp[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	while (1) {
		if (isEnd()) {
			if (allMelted) {
				cout << 0;
				break;
			}
			cout << cnt;
			break;
		}
		melt();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}
		cnt++;
	}
	return 0;
}