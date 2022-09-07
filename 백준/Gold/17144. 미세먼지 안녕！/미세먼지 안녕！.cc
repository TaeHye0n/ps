#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int room[50][50];
int R, C, T;
int answer;
int copyroom[50][50];
int cleaner[2][2];

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void diffusion() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			copyroom[i][j] = room[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] != 0 && room[i][j] != -1) {
				int cnt = 0;
				int divide = room[i][j] / 5;
				for (int w = 0; w < 4; w++) {
					int ny = i + dy[w];
					int nx = j + dx[w];
					if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
					if (room[ny][nx] != -1) {
						copyroom[ny][nx] = copyroom[ny][nx] + divide;
						cnt++;
					}
				}
				copyroom[i][j] = copyroom[i][j] - (divide * cnt);
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			room[i][j] = copyroom[i][j];
		}
	}
}
void aircleaner() {
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			for (int y = cleaner[i][0] - 1; y > 0; y--) {
				room[y][0] = room[y - 1][0];
			}
			for (int x = 0; x < C-1; x++) {
				room[0][x] = room[0][x + 1];
			}
			for (int y = 0; y < cleaner[i][0]; y++) {
				room[y][C - 1] = room[y + 1][C - 1];
			}
			for (int x = C - 1; x > 1; x--) {
				room[cleaner[i][0]][x] = room[cleaner[i][0]][x - 1];
			}
			room[cleaner[i][0]][1] = 0;
		}
		else {
			for (int y = cleaner[i][0] + 1; y < R-1; y++) {
				room[y][0] = room[y + 1][0];
			}
			for (int x = 0; x < C - 1; x++) {
				room[R - 1][x] = room[R - 1][x + 1];
			}
			for (int y = R - 1; y > cleaner[i][0]; y--) {
				room[y][C - 1] = room[y - 1][C - 1];
			}
			for (int x = C - 1; x > 1; x--) {
				room[cleaner[i][0]][x] = room[cleaner[i][0]][x - 1];
			}
			room[cleaner[i][0]][1] = 0;
		}
	}
}
int main() {
	
	cin >> R >> C >> T;
	int k = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				cleaner[k][0] = i;
				cleaner[k][1] = j;
				k++;
			}
		}
	}
	for (int i = 1; i <= T; i++) {
		diffusion();
		aircleaner();
	/*	cout << endl;*/
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] != -1) answer += room[i][j];
		/*	cout << room[i][j] << ' ';
			if (j == C - 1) cout << endl;*/
		}
	}
	cout << answer;

	return 0;
}