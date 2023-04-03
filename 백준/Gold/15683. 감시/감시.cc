#include <iostream>
#include <vector>
using namespace std;

int N, M;
int office[9][9];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
bool visited[9][9];
int sum;
int ans;
vector<pair<int, int>> v;

int cctv[6][4] = { // 북동남서
   {0,0,0,0},
   {0,1,0,0},
   {0,1,0,1},
   {1,1,0,0},
   {1,1,0,1},
   {1,1,1,1}
};

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp = 0;
			cin >> temp;
			office[i][j] = temp;
			if (temp != 0) {
				visited[i][j] = true;
				if (temp != 6) {
					sum++;
					v.push_back({ i,j });
				}
			}
			else ans++;
		}
	}
}

void rotate(int arr[]) {
	int temp = arr[3];
	for (int i = 2; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = temp;
}

void recur(int cnt, int idx) {
	if (cnt == sum + 1) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j]) temp++;
			}
		}
		if (ans > temp) ans = temp;
		return;
	}

	int i = idx;
	int y = v[i].first;
	int x = v[i].second;
	int value = office[y][x];
	int attempts = 0;
	if (value == 1 || value == 3 || value == 4) attempts = 4;
	else if (value == 2) attempts = 2;
	else attempts = 1;
	int arr[4] = { 0, };
	for (int j = 0; j < 4; j++) {
		arr[j] = cctv[value][j];
	}
	for (int j = 0; j < attempts; j++) {
		vector<pair<int, int>> temp;
		for (int w = 0; w < 4; w++) {
			if (arr[w] == 0) continue;
			int ny = y + dy[w] * arr[w];
			int nx = x + dx[w] * arr[w];
			while (1) {
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;
				if (office[ny][nx] == 6) break;
				if (office[ny][nx] == 0 && !visited[ny][nx]) temp.push_back({ ny,nx });
				visited[ny][nx] = true;
				ny = ny + dy[w] * arr[w];
				nx = nx + dx[w] * arr[w];
			}
		}
		recur(cnt + 1, i + 1);
		for (int k = 0; k < temp.size(); k++) {
			visited[temp[k].first][temp[k].second] = false;
		}
		if (j == attempts - 1) continue;
		rotate(arr);

	}
}

void solve() {
	recur(1, 0);
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