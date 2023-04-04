#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 16;
const int INF = 987654321;
int n, m;
int map[MAX][MAX];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
bool cantMove[MAX][MAX];
vector<pair<int, int>> store;
int ans;
bool inputFinished;

struct people {
	int curY, curX, destY, destX;
	bool arrived;
};

vector<people> p;

void chooseCamp(int idx) {
	queue<pair<int, int>> q;
	int visited[MAX][MAX];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = -1;
		}
	}
	q.push({ store[idx].first, store[idx].second });
	visited[store[idx].first][store[idx].second] = 0;
	vector<pair<int, int>> v;
	int dist = INF;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (!cantMove[ny][nx] && visited[ny][nx] == -1) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
				if (map[ny][nx] == 1) v.push_back({ ny,nx });
			}
		}
	}
	int y = MAX-1;
	int x = MAX-1;
	for (int i = 0; i < v.size(); i++) {
		if (dist >= visited[v[i].first][v[i].second]) {
			dist = visited[v[i].first][v[i].second];
			if (y > v[i].first) {
				y = v[i].first;
				x = v[i].second;
			}
			else if (y == v[i].first && x > v[i].second) {
				y = v[i].first;
				x = v[i].second;
			}
		}
	}
	cantMove[y][x] = true;
	p.push_back({ y,x,store[idx].first, store[idx].second, false });
}
int chooseDirection(people p1) {
	int dir = 0;
	int dist = INF;

	for (int w = 0; w < 4; w++) {
		queue<pair<int, int>> q;
		int y = p1.curY + dy[w];
		int x = p1.curX + dx[w];
		if (y < 0 || x < 0 || y >= n || x >= n) continue;
		q.push({ y,x });
		int visited[MAX][MAX];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = -1;
			}
		}
		visited[y][x] = 0;
		while (!q.empty()) {
			int yy = q.front().first;
			int xx = q.front().second;
			q.pop();
			if (yy == p1.destY && xx == p1.destX) {
				if (dist > visited[yy][xx]) {
					dir = w;
					dist = visited[yy][xx];
					break;
				}
			}
			for (int i = 0; i < 4; i++) {
				int ny = yy + dy[i];
				int nx = xx + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;

				if (!cantMove[ny][nx] && visited[ny][nx] == -1) {
					q.push({ ny,nx });
					visited[ny][nx] = visited[yy][xx] + 1;
				}
			}
		}
	}
	return dir;
}

void solve(int idx) {
	ans++;
	bool isFinished = true;
	//1
	for (int i = 0; i < p.size(); i++) {
		if (p[i].arrived == true) continue;
		int dir = chooseDirection(p[i]);
		p[i].curY += dy[dir];
		p[i].curX += dx[dir];

		// 2
		if (p[i].curY == p[i].destY && p[i].curX == p[i].destX) {
			p[i].arrived = true;
			cantMove[p[i].destY][p[i].destX] = true;
		}
	}


	//3 베이스캠프 들어가기
	if (!inputFinished)chooseCamp(idx);
	if (idx == m - 1) {
		inputFinished = true;

		for (int i = 0; i < p.size(); i++) {
			if (p[i].arrived == false) isFinished = false;
		}
		if (!isFinished) solve(idx);
	}
}
int main() {
	// 여기에 코드를 작성해주세요.
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		store.push_back({ a,b });
		solve(i);
	}
	cout << ans;
	return 0;
}
