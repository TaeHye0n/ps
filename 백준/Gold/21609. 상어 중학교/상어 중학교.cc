#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct group {
	int size;
	int rainbowCnt;
	int y; // 기준 블럭
	int x;
	vector<pair<int, int>> pos;
};

const int MAX = 21;
const int dy[4] = { -1,0,0,1 };
const int dx[4] = { 0,-1,1,0 };
int N;// 격자 한변의 크기
int M; // 색상의 개수 (검은색 무지개 제외)
int map[MAX][MAX];
bool visited[MAX][MAX];
bool rainbowVisited[MAX][MAX];
vector<group> groups;
bool isEnd;
int ans;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

bool compareGroups(group g1, group g2) {
	if (g1.size == g2.size) {
		if (g1.rainbowCnt == g2.rainbowCnt) {
			if (g1.y == g2.y) {
				return g1.x > g2.x;
			}return g1.y > g2.y;
		} return g1.rainbowCnt > g2.rainbowCnt;
	}return g1.size > g2.size;
}

void bfs(int a, int b, int color) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rainbowVisited[i][j] = false;
		}
	}
	queue<pair<int, int>> q;
	vector<pair<int, int>> allBlocks;
	q.push({ a,b });
	allBlocks.push_back({ a,b });
	visited[a][b] = true;
	int miny = a;
	int minx = b;
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

			if (map[ny][nx] == 0 && rainbowVisited[ny][nx] == false) {
				q.push({ ny,nx });
				rainbowVisited[ny][nx] = true;
				allBlocks.push_back({ ny,nx });
				cnt++;
			}
			else if (map[ny][nx] == color && visited[ny][nx] == false) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
				allBlocks.push_back({ ny,nx });
				if (miny > ny) {
					miny = ny;
					minx = nx;
				}
				else if (miny == ny && minx > nx) {
					minx = nx;
				}
			}
		}
	}
	if (allBlocks.size() < 2) return;
	group g;
	g.y = miny;
	g.x = minx;
	g.size = allBlocks.size();
	g.rainbowCnt = cnt;
	g.pos = allBlocks;
	groups.push_back(g);
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
	groups.clear();
	// 가장 큰 그룹 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] > 0) {
				bfs(i, j, map[i][j]);
			}
		}
	}
	if (groups.empty()) {
		isEnd = true;
		return;
	}
	sort(groups.begin(), groups.end(), compareGroups);
	group maxGroup = groups[0];

	// 가장 큰 그룹 제거
	for (int i = 0; i < maxGroup.pos.size(); i++) {
		int y = maxGroup.pos[i].first;
		int x = maxGroup.pos[i].second;
		map[y][x] = -2;
	}
	ans += maxGroup.size * maxGroup.size;

	// 중력 작용
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] <= -1) continue;
			int ny = i;
			while (1) {
				ny++;
				if (ny >= N || map[ny][j] != -2) {
					ny--;
					break;
				}
			}
			int temp = map[i][j];
			map[i][j] = -2;
			map[ny][j] = temp;
		}
	}

	// 반시계로 90도 회전
	int newMap[MAX][MAX] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			newMap[i][j] = map[j][N - i - 1];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = newMap[i][j];
		}
	}

	// 중력 작용
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] <= -1) continue;
			int ny = i;
			while (1) {
				ny++;
				if (ny >= N || map[ny][j] != -2) {
					ny--;
					break;
				}
			}
			int temp = map[i][j];
			map[i][j] = -2;
			map[ny][j] = temp;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	while (!isEnd) {
		solve();
	}
	cout << ans;
	return 0;
}