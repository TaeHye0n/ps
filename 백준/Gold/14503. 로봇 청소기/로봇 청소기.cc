#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[51][51];
bool vi[51][51];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int answer = 0;

struct robot {
	int y, x, dir;
};
robot s;


void input() {
	cin >> N >> M;
	cin >> s.y >> s.x >> s.dir;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];	
		}
	}
}
int changeDir(int dir) {
	if (dir == 0) return 3;
	else if (dir == 3) return 2;
	else if (dir == 2) return 1;
	else return 0;
}
void bfs() {
	queue<robot> q;
	q.push(s);

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();

		if (!vi[y][x]) {
			vi[y][x] = true;
			answer++;
		}

		bool flag = false;
		int ndir = dir;
		for (int w = 0; w < 4; w++) {
			 ndir = changeDir(ndir);

			int ny = y + dy[ndir];
			int nx = x + dx[ndir];

			if (ny <  0 || nx < 0 || ny >= N || nx >= M)continue;
			if (!vi[ny][nx] && map[ny][nx] != 1) {
				q.push({ ny,nx,ndir });
				flag = true;
				break;
			}
		}

		if (!flag) {
			int backDir = (dir + 2) % 4;
			int ny = y + dy[backDir];
			int nx = x + dx[backDir];

			if (ny <  0 || nx < 0 || ny >= N || nx >= M)continue;

			if (map[ny][nx] != 1) {
				q.push({ ny,nx,dir });
				continue;
			}
			else break;
		}

	}

}
int main() {
	input();
	bfs();
	cout << answer;
	return 0;
}