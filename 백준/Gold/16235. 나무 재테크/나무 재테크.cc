#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 11;
const int dy[8] = { 1,0,-1,0,1,-1,1,-1 };
const int dx[8] = { 0,1,0,-1,1,-1,-1,1 };
int N; // 땅 크기
int M; // 심은 나무의 개수
int K; // 년수
int A[MAX][MAX]; // 로봇이 뿌리는 양분
int map[MAX][MAX]; // 땅에 있는 양분
int ans;
vector<int> tree[MAX][MAX];

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][b].push_back(c);
	}
}

void solve() {
	//봄, 여름
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() == 0) continue;
			sort(tree[i][j].begin(), tree[i][j].end());
			vector<int> temp;
			int store = 0;

			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (map[i][j] >= age) {
					map[i][j] -= age;
					temp.push_back(age + 1);
				}
				else store += age / 2;
			}
			tree[i][j].clear();
			for (int k = 0; k < temp.size(); k++) {
				tree[i][j].push_back(temp[k]);
			}
			map[i][j] += store;
		}
	}

	//가을
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() == 0) continue;
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 == 0) {
					for (int w = 0; w < 8; w++) {
						int ny = i + dy[w];
						int nx = j + dx[w];

						if (ny < 1 || nx < 1 || ny >N || nx > N) continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}
	}

	// 겨울
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += A[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	while (K--) solve();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans;
	return 0;
}