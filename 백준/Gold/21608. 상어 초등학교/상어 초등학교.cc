#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int like[401][5];
int N;
int seat[21][21];
struct near{
	int y, x;
	int emptyCnt;
	int likeCnt;
};


bool cmp(near n1, near n2) {
	if (n1.likeCnt == n2.likeCnt) {
		if (n1.emptyCnt == n2.emptyCnt) {
			if (n1.y == n2.y) {
				return n1.x < n2.x;
			}return n1.y < n2.y;
		}return n1.emptyCnt > n2.emptyCnt;
	}return n1.likeCnt > n2.likeCnt;
}

int satisfactionCnt() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int std = seat[i][j];
			int cnt = 0;
			for (int w = 0; w < 4; w++) {
				int ny = i + dy[w];
				int nx = j + dx[w];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				for (int k = 0; k < 4; k++) {
					if (seat[ny][nx] == like[std][k]) cnt++;
				}
			}
			if (cnt == 1) res += 1;
			else if (cnt == 2) res += 10;
			else if (cnt == 3) res += 100;
			else if (cnt == 4) res += 1000;
		}
	}
	return res;
}
void solve(int c) {

	vector<near> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (seat[i][j] != 0) continue;
			int emptyCnt = 0;
			int likeCnt = 0;
			for (int w = 0; w < 4; w++) {
				int ny = i + dy[w];
				int nx = j + dx[w];
				bool flag = false;

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				for (int k = 0; k < 4; k++) {
					if (seat[ny][nx] != 0) {
						if (seat[ny][nx] == like[c][k]) {
							likeCnt++;
						}
						flag = true;
						continue;
					}
				}
				if (!flag) emptyCnt++;
			}
			v.push_back({ i,j,emptyCnt,likeCnt });
		}
	}
	sort(v.begin(), v.end(), cmp);
	seat[v[0].y][v[0].x] = c;
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			seat[i][j] = 0;
		}
	}
}

void input() {
	cin >> N;
	init();
	for (int i = 0; i < N * N; i++) {
		int c = 0;
		cin >> c;
		for (int j = 0; j < 4; j++) {
			cin >> like[c][j];
		}
		solve(c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	input();
	cout << satisfactionCnt();
	return 0;
}