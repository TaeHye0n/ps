#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int x, y, d, g;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int answer;
int coordinate[101][101];
vector<int> directionInfo;

void makeDragonCurve() {
	int size = directionInfo.size();
	for (int i = size - 1; i >= 0; i--) {
		int nextDirection = (directionInfo[i] + 1) % 4;
		x += dx[nextDirection];
		y += dy[nextDirection];
		coordinate[y][x] = 1;

		directionInfo.push_back(nextDirection);
	}
}

void countSquare() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i + 1 >= 101 || j + 1 >= 101) continue;
			if (coordinate[i][j] == 1 && coordinate[i + 1][j] == 1 && coordinate[i][j + 1] == 1 && coordinate[i + 1][j + 1] == 1) answer++;
		}
	}
	cout << answer;
}
void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		directionInfo.clear();
		coordinate[y][x] = 1;
		x += dx[d];
		y += dy[d];
		coordinate[y][x] = 1;
		directionInfo.push_back(d);
		for (int j = 0; j < g; j++) {
			makeDragonCurve();
		}
	}
	countSquare();
}

int main() {
	solve();
	return 0;
}
