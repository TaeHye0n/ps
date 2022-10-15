#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include<climits>
using namespace std;

int N, M;
int map[51][51];
int copyMap[51][51];
int vi[51][51];
int answer = INT_MAX;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
vector<pair <int, int>> v, temp;
vector<int> t;
struct virus {
	int y, x;
};

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back({ i,j });
		}
	}
}
void copy(int a[51][51], int b[51][51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void bfs() {
	int final[51][51];
	copy(final, map);
	queue<virus> q;

	for (int i = 0; i < temp.size(); i++) {
		q.push({ temp[i].first, temp[i].second });
		vi[temp[i].first][temp[i].second] = 0;
	}
	
	while (!q.empty()) {

		
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (final[ny][nx] != 1 && vi[ny][nx] ==-1) {
				q.push({ ny,nx });
				vi[ny][nx] = vi[y][x] + 1;
			}
		}
	}

	int time = 0;
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				if (vi[i][j] == -1) {
					flag = false;
					break;
				}
				else
					time = max(time, vi[i][j]);
			}
		}
	}
	if (flag) answer = min(answer, time);
}

void comb(int idx, int cnt) {
	if (cnt == M) {
		memset(vi, -1, sizeof(vi));
		bfs();
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		temp.push_back(v[i]);
		comb(i + 1, cnt + 1);
		temp.pop_back();
	}
}



int main() {
	input();
	comb(0, 0);

	if(answer == INT_MAX)
		cout << -1;
	else
	cout << answer;
	return 0;
}