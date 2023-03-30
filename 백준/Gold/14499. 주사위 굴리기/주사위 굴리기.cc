#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[21][21];
int K;
int y, x;
vector<int> cmd;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
vector<int> dice(6);
vector<int> ans;

void input() {
	cin >> N >> M;
	cin >> y >> x;
	cin >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		a--;
		cmd.push_back(a);
	}
}

void rotate(int dir) {
	if (dir == 0) { // 동쪽
		dice = { dice[3], dice[1], dice[0], dice[5], dice[4], dice[2] };
	}
	else if (dir == 1) { // 서쪽
		dice = { dice[2], dice[1], dice[5], dice[0], dice[4], dice[3] };
	}
	else if (dir == 2) { // 북쪽
		dice = { dice[4], dice[0], dice[2], dice[3], dice[5], dice[1] };
	}
	else { // 남쪽
		dice = { dice[1], dice[5], dice[2], dice[3], dice[0], dice[4] };
	}
}
void solve() {
	for (int i = 0; i < K; i++) {
		int dir = cmd[i];
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

		rotate(dir);
		if (map[ny][nx] == 0) map[ny][nx] = dice[5];
		else {
			dice[5] = map[ny][nx];
			map[ny][nx] = 0;
		}
		y = ny;
		x = nx;
		ans.push_back(dice[0]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}