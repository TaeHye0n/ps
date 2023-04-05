#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int map[5][5];
int isShark[5][5];
int ans;

struct fish {
	int y, x;
	int dir;
	bool isDead;
};
fish fishes[17];

int changeDir(int w) {
	return (w + 1) % 8;
}
void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			dir--;
			map[i][j] = num;
			fishes[num] = { i,j,dir,false };
		}
	}
}
void dfs(int sum, int num) {
	if (ans < sum) ans = sum;
	//복사
	fish fishes2[17];
	int map2[5][5];
	for (int i = 1; i <= 16; i++) {
		fishes2[i] = fishes[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map2[i][j] = map[i][j];
		}
	}
	// 물고기 이동
	for (int i = 1; i <= 16; i++) {
		int y = fishes[i].y;
		int x = fishes[i].x;
		int &dir = fishes[i].dir;
		if (map[y][x] == 0 || fishes[i].isDead) continue;
		bool canMove = false;
		int changeCnt = 0;
		while (!canMove) {
			if (changeCnt > 7) break;
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny >= 0 && nx >= 0 && ny < 4 && nx < 4 && isShark[ny][nx] == 0) {
				canMove = true;
				int num = map[ny][nx];
			
				fishes[i].y = ny;
				fishes[i].x = nx;
				fishes[num].y = y;
				fishes[num].x = x;
				map[ny][nx] = i;
				map[y][x] = num;
			}
			else {
				dir = changeDir(dir);
				changeCnt++;
			}
		}
	}

  	int y = fishes[num].y;
	int x = fishes[num].x;
	int dir = fishes[num].dir;
	for (int i = 1; i <= 3; i++) {
		int ny = y + dy[dir] * i;
		int nx = x + dx[dir] * i;

		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {

			if (map[ny][nx] == 0) continue;
			int temp = map[ny][nx];
			map[ny][nx] = 0;
			isShark[ny][nx] = 1;
			fishes[temp].isDead = true;
			isShark[y][x] = 0;
 			dfs(sum + temp, temp);
			map[ny][nx] = temp;
			fishes[temp].isDead = false;
			isShark[ny][nx] = 0;
			isShark[y][x] = 1;
		}
		else break;
	}
	// 이동 되돌리기
	for (int i = 1; i <= 16; i++) {
		fishes[i] = fishes2[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = map2[i][j];
		}
	}
}
void solve() {

	// 상어 입장
	int temp = map[0][0];
	map[0][0] = 0;
	isShark[0][0] = 1;
	fishes[temp].isDead = true;
	// 상어 이동
	dfs(temp, temp);

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