#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int answer = 0;
	int N, M, K;
	cin >> N >> M >> K;
	bool visited[101][101] = { false, };
	int board[101][101] = { 0, };
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = true;
				int cnt = 0;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					cnt++;

					for (int w = 0; w < 4; w++) {
						int ny = y + dy[w];
						int nx = x + dx[w];

						if (ny < 1 || nx < 1 || ny>N || nx >M) continue;

						if (board[ny][nx] == 1 && !visited[ny][nx]) {
							q.push({ ny,nx });
							visited[ny][nx] = true;
						}
					}
				}
				answer = max(answer, cnt);
			}
		}
	}
	cout << answer;
	return 0;
}