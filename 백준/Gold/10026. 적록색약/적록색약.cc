#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };
char realMap[MAX][MAX]; // 정상인이 본 색
char fakeMap[MAX][MAX]; // 적록색약이 본 색
bool realVisited[MAX][MAX];
bool fakeVisited[MAX][MAX];
int N; // 격자크기

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			realMap[i][j] = temp;
			if (temp == 'G') temp = 'R';
			fakeMap[i][j] = temp;
		}
	}
}
void bfs(int stY, int stX, char color, bool real) {
	queue<pair<int, int>> q;
	q.push({ stY,stX });
	if (real) {
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int w = 0; w < 4; w++) {
				int ny = y + dy[w];
				int nx = x + dx[w];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (realMap[ny][nx] == color && !realVisited[ny][nx]) {
					q.push({ ny,nx });
					realVisited[ny][nx] = true;
				}
			}
		}
	}
	else {
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int w = 0; w < 4; w++) {
				int ny = y + dy[w];
				int nx = x + dx[w];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (fakeMap[ny][nx] == color && !fakeVisited[ny][nx]) {
					q.push({ ny,nx });
					fakeVisited[ny][nx] = true;
				}
			}
		}
	}
}
void solve() {
	// 정상인 구역 숫자 구하기
	int realCnt = 0;
	int fakeCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (realVisited[i][j]) continue;
			realVisited[i][j] = true;
			bfs(i, j, realMap[i][j], true);
			realCnt++;
			if (fakeVisited[i][j]) continue;
			fakeVisited[i][j] = true;
			bfs(i, j, fakeMap[i][j], false);
			fakeCnt++;
		}
	}
	cout << realCnt << " " << fakeCnt << "\n";
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
}