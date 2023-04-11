#include <iostream>
#define MAX 21
using namespace std;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };
bool used[26];
bool visited[MAX][MAX];
int R, C;
int ans;
char map[MAX][MAX];

void recur(int y, int x, int cnt) {
	ans = max(ans, cnt);

	for (int w = 0; w < 4; w++) {
		int ny = y + dy[w];
		int nx = x + dx[w];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		int cc = map[ny][nx];
		if (!visited[ny][nx] && !used[cc - 'A']) {
			visited[ny][nx] = true;
			used[cc - 'A'] = true;
			recur(ny, nx, cnt + 1);
			visited[ny][nx] = false;
			used[cc - 'A'] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	visited[0][0] = true;
	used[map[0][0] - 'A'] = true;
	recur(0, 0,  1);
	cout << ans;
	return 0;
}