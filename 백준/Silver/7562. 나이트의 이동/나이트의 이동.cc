#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
const int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int l; // 체스판 한변의 길이
		cin >> l;
		int stx, sty, dtx, dty;
		cin >> stx >> sty;
		cin >> dtx >> dty;

		queue<pair<int, int>> q;
		vector<vector<int>> visited;
		visited.assign(l, vector<int>(l, 0));

		q.push({ stx,sty });

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == dtx && y == dty) {
				cout << visited[x][y] << "\n";
				break;
			}

			for (int w = 0; w < 8; w++) {
				int nx = x + dx[w];
				int ny = y + dy[w];

				if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;

				if (visited[nx][ny] == 0) {
					q.push({ nx,ny });
					visited[nx][ny] = visited[x][y] + 1;
				}
			}
		}

	}

	return 0;
}