#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 21;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,-1,0,1 };
int N; // 공간의 크기
int M =2; // 아기상어 크기
int Y, X; // 아기상어 위치
int map[MAX][MAX];
int ans = 0;
int cnt = 0; // 먹은 물고기 숫자

struct fish {
	int y, x;
	int dist;
};

bool cmp(fish f1, fish f2) {
	if (f1.dist == f2.dist) {
		if (f1.y == f2.y) return f1.x < f2.x;
		return f1.y < f2.y;
	} return f1.dist < f2.dist;
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 9) {
				Y = i;
				X = j;
			}
		}
	}
}

void solve() {
	while (1) {
		queue<pair<int, int>> q;
		int visited[MAX][MAX];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = -1;
			}
		}
		q.push({ Y,X });
		visited[Y][X] = 0;
		vector<fish> v;

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int w = 0; w < 4; w++) {
				int ny = y + dy[w];
				int nx = x + dx[w];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

				if (visited[ny][nx] == -1 && map[ny][nx] != 9 && map[ny][nx] <= M) {
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
					if (map[ny][nx] < M && map[ny][nx] > 0) v.push_back({ ny,nx,visited[ny][nx] });
				}
			}
		}
		if (!v.empty()) {
			sort(v.begin(), v.end(), cmp);
			map[Y][X] = 0;
			Y = v[0].y, X = v[0].x;
			cnt++;
		}
		else break;
		
		if (M == cnt) {
			M++;
			cnt = 0;
		}
		map[Y][X] = 9;
		ans += v[0].dist;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	cout << ans;
	return 0;
}