#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N;
int L, R;
int region[51][51];
int ans;
bool flag;


void input() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> region[i][j];
		}
	}
}

void solve() {
	int visited[51][51];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
	flag = false;
	queue<pair<int, int>> q;
	vector<pair<int, int>> temp;
	int pivot = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				int sum = region[i][j];
				int cnt = 0;
				q.push({ i,j });
				visited[i][j] = pivot;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int w = 0; w < 4; w++) {
						int ny = y + dy[w];
						int nx = x + dx[w];

						if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

						int sub = abs(region[y][x] - region[ny][nx]);
						if (sub >= L && sub <= R && visited[ny][nx] == 0) {
							cnt++;
							sum += region[ny][nx];
							visited[ny][nx] = pivot;
							q.push({ ny,nx });
						}
					}
				}
				if (cnt >= 1) {
					flag = true;
					int res = sum / (cnt + 1);
					temp.push_back({ pivot,res });
				}
				else visited[i][j] = 0;
				pivot++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < temp.size(); k++) {
				if (visited[i][j] == temp[k].first) region[i][j] = temp[k].second;
			}
		}
	}
	if (flag) {
		ans++;
		solve();
	}
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