#include<iostream>
#include<queue>

using namespace std;
// [면][행][열] = [z][y][x]
int vi[101][101][101];
int arr[101][101][101]; 
queue < pair<pair<int, int>, int>> q;
int N, M, H,ans;
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

void solve() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				vi[i][j][k] = -1;
				if (arr[i][j][k] == 1 && vi[i][j][k] == -1) {
					q.push({ {i,j},k });
					vi[i][j][k] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		int z = q.front().first.first;
		int y = q.front().first.second;
		int x = q.front().second;
		q.pop();

		for (int w = 0; w < 6; w++) {
			int nz = z + dz[w];
			int ny = y + dy[w];
			int nx = x + dx[w];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
			if (arr[nz][ny][nx] == 0 && vi[nz][ny][nx] == -1) {
				q.push({ {nz,ny},nx });
				vi[nz][ny][nx] = vi[z][y][x] + 1;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				ans = max(ans, vi[i][j][k]);
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0 && vi[i][j][k] == -1) ans = -1;
			}
		}
	}
}


int main() {
	cin >> M >> N >> H;
	solve();
	cout << ans << endl;
	return 0;
}