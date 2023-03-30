#include<iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

const int pipe[8][4] = {
	{0,0,0,0},
	{1,1,1,1},
	{1,0,1,0},
	{0,1,0,1},
	{1,1,0,0},
	{0,1,1,0},
	{0,0,1,1},
	{1,0,0,1}
};



int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 

	int T;
	cin >> T;
	int cnt = 0;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

	
	while (T--) {
		int ans = 0;
		int N, M = 0;
		int y, x = 0;
		int time = 0;

		cin >> N >> M >> y >> x >> time;

		int arr[51][51] = { 0, };
		int visited[51][51] = { 0, };
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}

		queue<pair<int, int>> q;
		q.push({ y,x });
		visited[y][x] = 1;

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			int value = arr[y][x];
			q.pop();
			if (visited[y][x] == time) break;

			for (int w = 0; w < 4; w++) {
				if (pipe[value][w] == 0) continue;
				int ny = y + dy[w] * pipe[value][w];
				int nx = x + dx[w] * pipe[value][w];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

				if (arr[ny][nx] != 0 && visited[ny][nx] == 0) {
					int value2 = arr[ny][nx];
					bool isLinked = false;
					for (int i = 0; i < 4; i++) {
						if (pipe[value2][i] == 0) continue;
						int ny2 = ny + dy[i] * pipe[value2][i];
						int nx2 = nx + dx[i] * pipe[value2][i];
						
						if (ny2 < 0 || nx2 < 0 || ny >= N || nx >= M) continue;
						if (ny2 == y && nx2 == x) isLinked = true;
					}
					if (!isLinked) continue;
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] != 0) ans++;
			}
		}
		cout << "#" << ++cnt << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}