#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;
int r, c, k;
int A[MAX][MAX];
bool flag;
int times;
int ans;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}
void input() {
	cin >> r >> c >> k;
	r--; c--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			cin >> temp;
			A[i][j] = temp;
			if (A[r][c] == k) flag = true;
		}
	}
}

void solve() {
	int row = 3, col = 3;
	while (!flag) {
		times++;
		if (times > MAX) {
			ans = -1;
			break;
		}
		vector<pair<int, int>> v[MAX];
		if (row >= col) {
			for (int i = 0; i < row; i++) {
				int cnt[MAX + 1] = { 0, };
				for (int j = 0; j < col; j++) {
					if(A[i][j] != 0) cnt[A[i][j]]++;
				}
				for (int j = 1; j < MAX + 1; j++) {
					if (cnt[j] != 0) v[i].push_back({ j, cnt[j] });
				}
				sort(v[i].begin(), v[i].end(), cmp);
			}
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					A[i][j] = 0;
				}
			}

			for (int i = 0; i < row; i++) {
				int idx = 0;
				for (int j = 0; j < v[i].size(); j++) {
					A[i][idx++] = v[i][j].first;
					if (idx >= MAX) break;
					A[i][idx++] = v[i][j].second;
					if (idx >= MAX) break;
				}
				col = max(col, idx);
			}
		}
		else {
			for (int i = 0; i < col; i++) {
				int cnt[MAX + 1] = { 0, };
				for (int j = 0; j < row; j++) {
					if (A[j][i] != 0) cnt[A[j][i]]++;
				}
				for (int j = 1; j < MAX + 1; j++) {
					if (cnt[j] != 0) v[i].push_back({ j, cnt[j] });
				}
				sort(v[i].begin(), v[i].end(), cmp);
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					A[i][j] = 0;
				}
			}

			for (int i = 0; i < col; i++) {
				int idx = 0;
				for (int j = 0; j < v[i].size(); j++) {
					A[idx++][i] = v[i][j].first;
					if (idx >= MAX) break;
					A[idx++][i] = v[i][j].second;
					if (idx >= MAX) break;
				}
				row = max(row, idx);
			}
		}

		if (A[r][c] == k) {
			flag = true;
			ans = times;
			break;
		}
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