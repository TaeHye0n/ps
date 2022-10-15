#include<iostream>
using namespace std;


int N, L;
int map[101][101];
int map2[101][101];
int answer;

void input() {
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			map2[j][i] = map[i][j];
		}
	}
}

bool canMakeRoad(int a[101][101], int x, int y) {
	int current = a[x][y + 1];
	for (int i = y + 1; i < y + 1 + L; i++) {
		if (a[x][i] != current)return false;
	}

	return true;
}

void makeRoad(int A[101][101]) {

	for (int i = 1; i <= N; i++) {
		bool isRoad = true;
		int count = 1;

		for (int j = 1; j < N; j++) {
			if (A[i][j] == A[i][j + 1]) count++;
			else if (A[i][j] == A[i][j + 1] + 1) {
				if (canMakeRoad(A, i, j)) {
					j = j + L - 1;
					count = 0;
				}
				else {
					isRoad = false;
					break;
				}
			}
			else if (A[i][j] == A[i][j + 1] - 1) {
				if (count >= L) {
					count = 1;
				}
				else {
					isRoad = false;
					break;
				}
			}
			else if (abs(A[i][j] - A[i][j + 1]) > 1) {
				isRoad = false;
				break;
			}
		}
		if (isRoad) {
			answer++;
		}
	}
}

void solve() {
	makeRoad(map);
	makeRoad(map2);
}

int main() {
	input();
	solve();
	cout << answer;
	return 0;
}