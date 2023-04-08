#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int map[500][500];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
int ratio[9] = { 1,1,2,7,7,2,10,10,5 };
int blowY[4][10] = {
    {-1,1,-2,-1,1,2,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{1,1,0,0,0,0,-1,-1,-2,-1}
};
int blowX[4][10] = {
    {1,1,0,0,0,0,-1,-1,-2,-1},
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,-1,1,2,-1,1,0,0}
};
int answer;

void input() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];	
		}
	}
}

bool inRange(int y, int x) {
	return y >= 0 && x >= 0 && y < N&& x < N;
}
void blowSand(int y, int x, int dir) {
	int first = map[y][x];

	for (int i = 0; i < 10; i++) {
		int sand = 0;
		if (i != 9) {
			sand = first * ratio[i] / 100;
			map[y][x] -= sand;
		}
		else sand = map[y][x];

		int by = y + blowY[dir % 4][i];
		int bx = x + blowX[dir % 4][i];

		if (by < 0 || bx < 0 || by >= N || bx >=N) {
			answer += sand;
			continue;
		}
		map[by][bx] += sand;
	}
	map[y][x] = 0;
}

void solve() {
	int y = N / 2, x = N / 2, dir = 0;
	for (double i = 1.0; i <= N; i += 0.5) {
		for (int j = 0; j < (int)i; j++) {
			y += dy[dir % 4];
			x += dx[dir % 4];
			blowSand(y, x, dir);
		}
		dir++;
	}

}
int main() {
	input();
	solve();

	cout << answer;
	return 0;
}