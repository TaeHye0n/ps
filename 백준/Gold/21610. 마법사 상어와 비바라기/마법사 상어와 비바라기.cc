#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int ans;
int A[51][51];
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
vector<pair<int, int>> cmd;
bool cloud[51][51];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cmd.push_back({ a,b });
	}

	for (int i = 1; i <= 2; i++) {
		cloud[N][i] = true;
		cloud[N - 1][i] = true;
	}
}

void solve() {
	for (int k = 0; k < M; k++) {
		// 1. 모든 구름 이동
		int dir = cmd[k].first;
		dir--;
		int dist = cmd[k].second;
		queue<pair<int, int>> q;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (cloud[i][j]) {
					q.push({ i,j });
					cloud[i][j] = false;
				}
			}
		}
		queue<pair<int, int>> q2;
		while (!q.empty()) {
			int ny = q.front().first;
			int nx = q.front().second;
			q.pop();
			for (int d = 0; d < dist; d++) {
				ny += dy[dir];
				nx += dx[dir];

				if (ny > N) ny = 1;
				if (nx > N) nx = 1;
				if (ny < 1) ny = N;
				if (nx < 1) nx = N;
			}
			// 2. 이동 후 바구니에 저장된 물의 양 1 증가
			cloud[ny][nx] = true;
			A[ny][nx]++;
			q2.push({ ny,nx });
		}

		// 4. 물복사 버그 대각선 조사후 개수만큼 더하기
		while (!q2.empty()) {
			int y = q2.front().first;
			int x = q2.front().second;
			int cnt = 0;
			q2.pop();
			for (int w = 1; w < 8; w += 2) {
				int ny = y + dy[w];
				int nx = x + dx[w];

				if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
				if (A[ny][nx] != 0) cnt++;
			}
			A[y][x] += cnt;
		}

		// 5. 구름 생성
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (A[i][j] >= 2 && !cloud[i][j]) {
					A[i][j] -= 2;
					cloud[i][j] = true;
				}
				else if (cloud[i][j]) cloud[i][j] = false;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == 0) continue;
			ans += A[i][j];
		}
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	input();
	solve();
	return 0;
}