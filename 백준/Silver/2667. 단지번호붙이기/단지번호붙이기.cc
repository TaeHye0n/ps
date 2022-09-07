#include<iostream>
#include<queue>
#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, count_;
int arr[25][25];
bool vi[25][25];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<int> answer;

void solve(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	vi[a][b] = true;
	count_++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int w = 0; w < 4; w++) {
			int nx = x + dx[w];
			int ny = y + dy[w];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && vi[nx][ny] == false && arr[nx][ny] == 1) {
				q.push({ nx, ny });
				vi[nx][ny] = true;
				count_++;
			}

		}
	
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (arr[a][b] == 1 && vi[a][b] == false) {
				count_ = 0;
				solve(a, b);
				answer.push_back(count_);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return 0;
}