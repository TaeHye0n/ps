#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 20;
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 }
;
struct shark {
	int y, x;
	int dir;
	vector<int> prior[4];
	bool isDead;
};

int visited[MAX][MAX]; // 격자의 어떤 상어 냄새
int leftSmell[MAX][MAX]; // 격자에 남아있는 냄새량
shark sharks[MAX * MAX + 1];
int N; //격자 크기
int M; // 상어개수
int k; // 냄새 지속시간
int map[MAX][MAX];
int sharkCnt;
int ans;
vector<pair<int, pair<int, int>>> v;

void input() {
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) continue;
			sharks[map[i][j]] = { i,j,0 };
			visited[i][j] = map[i][j];
			leftSmell[i][j] = k;
		}
	}

	for (int i = 1; i <= M; i++) {
		int a;
		cin >> a;
		a--;
		sharks[i].dir = a;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int a;
				cin >> a;
				a--;
				sharks[i].prior[j].push_back(a);
			}
		}
	}
	sharkCnt = M;
}
void sharkMove(int idx) {
	int y = sharks[idx].y;
	int x = sharks[idx].x;
	int dir = sharks[idx].dir;
	for (int i = 0; i < sharks[idx].prior[dir].size(); i++) {
		int ndir = sharks[idx].prior[dir][i];
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];

		if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
			if (visited[ny][nx] == 0) {
				sharks[idx].y = ny;
				sharks[idx].x = nx;
				sharks[idx].dir = ndir;
				if (map[ny][nx] != 0) {
					sharks[idx].isDead = true;
					map[y][x] = 0;
					sharkCnt--;
					return;
				}
				map[ny][nx] = idx;
				map[y][x] = 0;
				v.push_back({ idx,{ny,nx} });
				return;
			}
		}
	}

	for (int i = 0; i < sharks[idx].prior[dir].size(); i++) {
		int ndir = sharks[idx].prior[dir][i];
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];

		if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
			if (visited[ny][nx] == idx) {
				sharks[idx].y = ny;
				sharks[idx].x = nx;
				sharks[idx].dir = ndir;
				if (map[ny][nx] != 0) {
					sharks[idx].isDead = true;
					map[y][x] = 0;
					sharkCnt--;
					return;
				}
				map[ny][nx] = idx;
				map[y][x] = 0;
				v.push_back({ idx,{ny,nx} });
				return;
			}
		}
	}

}
void solve() {
	v.clear();
	for (int i = 1; i <= M; i++) {
		if (sharks[i].isDead) continue;
		sharkMove(i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (leftSmell[i][j] == 0) continue;
			leftSmell[i][j]--;
			if (leftSmell[i][j] == 0)visited[i][j] = 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int y = v[i].second.first;
		int x = v[i].second.second;
		int idx = v[i].first;
		leftSmell[y][x] = k;
		visited[y][x] = idx;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	while (sharkCnt > 1) {
		ans += 1;
		solve();
		if (ans > 1000) {
			ans = -1;
			break;
		}
	}
	cout << ans;
	return 0;
}