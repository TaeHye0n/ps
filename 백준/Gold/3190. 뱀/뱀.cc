#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int N, K, L;
int board[101][101];
char swift[10001];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool isSnake[101][101];

void input() {

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y = 0;
		cin >> y >> x;
		board[y][x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int time = 0;
		char direction = ' ';
		cin >> time >> direction;
		swift[time] = direction;
	}
}

int main() {
	int answerTime = 0;
	input();
	deque<pair<int, int>> q;

	q.push_back({ 1,1 });
	isSnake[1][1] = true;
	int currentDirection = 0;

	while (1) {
		answerTime++;
		int ny = q.front().first + dy[currentDirection];
		int nx = q.front().second + dx[currentDirection];

		if (ny < 1 || ny > N || nx < 1 || nx > N) break;


		if (swift[answerTime] == 'D') {
			currentDirection += 1;
			if (currentDirection == 4) currentDirection = 0;
		}

		else if (swift[answerTime] == 'L') {
			currentDirection -= 1;
			if (currentDirection == -1) currentDirection = 3;
		}

		if (board[ny][nx] == 1) {
			board[ny][nx] = 0;
		}
		else {
			if (isSnake[ny][nx] == true) break;
			isSnake[q.back().first][q.back().second] = false;
			q.pop_back();
		}
		q.push_front({ ny,nx });

		if (isSnake[ny][nx] == true) break;
		else isSnake[ny][nx] = true;
	}

	cout << answerTime;
	return 0;
}
