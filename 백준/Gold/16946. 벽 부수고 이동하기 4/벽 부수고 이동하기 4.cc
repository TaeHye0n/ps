#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX 1010

using namespace std;
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };
int N, M;
int map[MAX][MAX];
int group[MAX*MAX];
int groupNum[MAX][MAX];
vector<pair<int, int>> walls;
int cnt;
bool visited[MAX][MAX];
bool isWall[MAX][MAX];
queue<pair<int, int>> q;

void makeGroup(int num) {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		groupNum[y][x] = num;

		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (map[ny][nx] == 0 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}

	group[num] = cnt;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) {
				walls.push_back({ i,j });
				isWall[i][j] = true;
			}
		}
	}
	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == false && map[i][j] == 0) {
				q.push({ i,j });
				cnt = 0;
				visited[i][j] = true;
				makeGroup(num);
				num++;
			}
		}
	}
	
	for (int i = 0; i < walls.size(); i++) {
		int y = walls[i].first;
		int x = walls[i].second;
		set<int> nums;
		for (int w = 0; w < 4; w++) {
			int ny = y + dy[w];
			int nx = x + dx[w];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (map[ny][nx] == 0 && isWall[ny][nx] == false) {
				nums.insert(groupNum[ny][nx]);
			}
		}

		for (auto itr = nums.begin(); itr != nums.end(); itr++) {
			map[y][x] += group[*itr];
		}
		map[y][x] %= 10;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}