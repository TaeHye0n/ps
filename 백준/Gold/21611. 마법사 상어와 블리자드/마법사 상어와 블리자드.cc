#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 50;
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int map[MAX][MAX];
int N; // 격자 크기
int M; // 블리자드 횟수
int dist, dir;
int cnt; // 전체구슬 개수
vector<int> bead; // 구슬들 저장
int ans;

int changeDir(int w) {
	if (w == 2) return 1;
	else if (w == 1) return 3;
	else if (w == 3) return 0;
	else return 2;
}

void saveBead() {
	bead.clear();
	int y = (N + 1) / 2;
	int x = y;
	int idx = 0;
	int w = 2;
	int length = 1;
	while (idx != cnt) {
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= length; j++) {
				int ny = y + dy[w];
				int nx = x + dx[w];
				if (ny > 0 && nx > 0 && ny <= N && nx <= N && map[ny][nx] != 0) {
					bead.push_back(map[ny][nx]);
					idx++;
				}
				y = ny;
				x = nx;
				if (idx == cnt) return;
			}
			w = changeDir(w);
		}
		length++;
	}
}

void updateMap() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
	}
	int y = (N + 1) / 2;
	int x = y;
	int idx = 0;
	int w = 2;
	int length = 1;
	while (idx != cnt) {
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= length; j++) {
				int ny = y + dy[w];
				int nx = x + dx[w];
				if (ny > 0 && nx > 0 && ny <= N && nx <= N) {
					map[ny][nx] = bead[idx++];
					y = ny;
					x = nx;
				}
				if (idx == cnt) return;
			}
			w = changeDir(w);
		}
		length++;
	}
}

void explode() {
	bool flag = true;
	while (flag) {
		vector<int> temp;
		int idx;
		flag = false;
		for (int i = 0; i < bead.size(); i++) {
			idx = i;;
			while (idx < bead.size() && bead[idx] == bead[i]) idx++;
			if (idx - i < 4) {
				for (int j = i; j < idx; j++) {
					temp.push_back(bead[j]);
				}
			}
			else {
				ans += bead[i] * (idx-i);
				flag = true;
			}
			i = idx-1;
		}
		bead = temp;
	}
}
void changeBead() {
	vector<int> temp;
	int idx;
	for (int i = 0; i < bead.size(); i++) {
		idx = i;
		while (idx < bead.size() && bead[idx] == bead[i]) idx++;
		temp.push_back(idx-i);
		temp.push_back(bead[i]);
		i = idx-1;
	}
	if (temp.size() >= N * N) {
		while (temp.size() >= N * N) temp.pop_back();
	}
	bead = temp;
	cnt = bead.size();
}
void solve() {
	//블리자드
	for (int i = 1; i <= dist; i++) {
		int ny = (N + 1) / 2 + dy[dir] * i;
		int nx = (N + 1) / 2 + dx[dir] * i;
		if (map[ny][nx] == 0) continue;
		map[ny][nx] = 0;
		cnt--;
	}
	saveBead();
	explode();
	changeBead();
	updateMap();
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) cnt++;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> dir >> dist;
		dir--;
		solve();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	cout << ans;
	return 0;
}