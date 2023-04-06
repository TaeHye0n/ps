#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
const int dx[8] = { -1,-1,0,1,1,1,0,-1 };
const int sharkdy[4] = { -1,0,1,0 };
const int sharkdx[4] = { 0,-1,0,1 };

struct fish {
	int y, x;
	int dir;
};
vector<fish> map[4][4];
vector<fish> copyMap[4][4]; // 복제를 위한 격자
pair<int, int> shark; // 상어의 위치
int smell[4][4]; // 격자에 남아 있는 물고기 냄새
int M; // 물고기의 수
int S; // 마법 연습 숫자
vector<int> routes[64];
int route[3];
int routeCnt;

int rotateDir(int dir) {
	return (dir + 7) % 8;
}
void input() {
	cin >> M >> S;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--; c--;
		map[a][b].push_back({ a,b,c });
	}
	int a, b;
	cin >> a >> b;
	a--; b--;
	shark = { a,b };
}

void moveFish() {
	vector<fish> temp[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j].empty()) continue;
			for (int k = 0; k < map[i][j].size(); k++) {
				int y = i;
				int x = j;
				int dir = map[i][j][k].dir;
				int ny = y;
				int nx = x;
				bool flag = false;
				for (int i = 0; i < 8; i++) {
					ny = y + dy[dir];
					nx = x + dx[dir];

					if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
						if ((ny != shark.first || nx != shark.second) && smell[ny][nx] == 0) {
							flag = true;
							break;
						}
					}
					dir = rotateDir(dir);
				}
				if (flag) {
					temp[ny][nx].push_back({ ny,nx,dir });
				}
				else {
					temp[y][x].push_back({ y,x,dir });
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = temp[i][j];
		}
	}
}

void makeRoute(int depth, vector<int> v) {
	if (depth == 3) {
		routes[routeCnt] = v;
		routeCnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		makeRoute(depth + 1, v);
		v.pop_back();
	}
}

void moveShark() {
	int maxSum = 0;
	int routeNum = 0;
	for (int i = 0; i < 64; i++) {
		int y = shark.first;
		int x = shark.second;
		int sum = 0;
		bool flag = true;
		bool visited[4][4] = { false, };
		for (int j = 0; j < 3; j++) {
			int dir = routes[i][j];
			int ny = y + sharkdy[dir];
			int nx = x + sharkdx[dir];

			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) {
				flag = false;
				break;
			}
			y = ny;
			x = nx;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			sum += map[ny][nx].size();
		}
		if (sum > maxSum && flag) {
			maxSum = sum;
			routeNum = i;
		}
	}
	if (maxSum == 0) {
		for (int i = 0; i < 64; i++) {
			int y = shark.first;
			int x = shark.second;
			int sum = 0;
			bool visited[4][4] = { false, };
			bool flag = true;
			for (int j = 0; j < 3; j++) {
				int dir = routes[i][j];
				int ny = y + sharkdy[dir];
				int nx = x + sharkdx[dir];

				if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) {
					flag = false;
					break;
				}
				y = ny;
				x = nx;
			}
			if (flag) {
				routeNum = i;
				break;
			}
		}
	}
	int y = shark.first;
	int x = shark.second;
	for (int j = 0; j < 3; j++) {
		int dir = routes[routeNum][j];
		int ny = y + sharkdy[dir];
		int nx = x + sharkdx[dir];

		if (map[ny][nx].size() >= 1) {
			map[ny][nx].clear();
			smell[ny][nx] = 3;
		}
		y = ny;
		x = nx;
	}
	shark.first = y;
	shark.second = x;
}
void solve() {
	// 1. 복제마법 준비
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copyMap[i][j] = map[i][j];
		}
	}

	// 2. 물고기 한 칸 이동
	moveFish();

	// 3. 상어가 연속해서 3칸 이동
	moveShark();

	// 4. 냄새 -1
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (smell[i][j] == 0) continue;
			smell[i][j]--;
		}
	}

	// 5. 복제 마법 완료
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < copyMap[i][j].size(); k++) {
				map[i][j].push_back(copyMap[i][j][k]);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	vector<int> temp;
	makeRoute(0, temp);
	for (int i = 1; i <= S; i++) {
		solve();
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ans += map[i][j].size();
		}
	}
	cout << ans;
	return 0;
}