#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 21

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
int diceNum[7] = {0, 1, 2, 3, 4, 5, 6};
int N, M, K;
int answer = 0;
int board[MAX][MAX];

struct pos {
    int y;
    int x;
    int dir;
};

void changeDiceStatus();

pos dice;

int reverseDir(int dir) {
    switch (dir) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 2;
    }
}

void getScore() {
    int y = dice.y;
    int x = dice.x;

    int B = board[y][x];

    queue<pair<int, int>> q;
    bool visited[MAX][MAX] = {false,};
    q.emplace(y, x);
    visited[y][x] = true;
    int cnt = 0;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        cnt++;

        for (int w = 0; w < 4; w++) {
            int ny = cy + dy[w];
            int nx = cx + dx[w];

            if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;

            if (!visited[ny][nx] && board[ny][nx] == B) {
                q.emplace(ny, nx);
                visited[ny][nx] = true;
            }
        }
    }

    answer += (cnt * B);
}

void moveDice() {
    int ny = dice.y + dy[dice.dir];
    int nx = dice.x + dx[dice.dir];

    if (ny <= 0 || nx <= 0 || ny > N || nx > M) {
        dice.dir = reverseDir(dice.dir);
        ny = dice.y + dy[dice.dir];
        nx = dice.x + dx[dice.dir];
    }
    dice.y = ny;
    dice.x = nx;
}

void changeDir() {
    if (diceNum[6] > board[dice.y][dice.x]) {
        switch (dice.dir) {
            case 0:
                dice.dir = 2;
                return;
            case 1:
                dice.dir = 3;
                return;
            case 2:
                dice.dir = 1;
                return;
            case 3:
                dice.dir = 0;
                return;
        }
    } else if (diceNum[6] < board[dice.y][dice.x]) {
        switch (dice.dir) {
            case 0:
                dice.dir = 3;
                return;
            case 1:
                dice.dir = 2;
                return;
            case 2:
                dice.dir = 0;
                return;
            case 3:
                dice.dir = 1;
                return;
        }
    }
}

void changeDiceStatus() {
    int d1 = diceNum[1];
    int d2 = diceNum[2];
    int d3 = diceNum[3];
    int d4 = diceNum[4];
    int d5 = diceNum[5];
    int d6 = diceNum[6];

    switch (dice.dir) {
        case 0:
            diceNum[1] = d4;
            diceNum[3] = d1;
            diceNum[6] = d3;
            diceNum[4] = d6;
            break;
        case 1:
            diceNum[1] = d3;
            diceNum[3] = d6;
            diceNum[6] = d4;
            diceNum[4] = d1;
            break;
        case 2:
            diceNum[1] = d2;
            diceNum[2] = d6;
            diceNum[6] = d5;
            diceNum[5] = d1;
            break;
        case 3:
            diceNum[1] = d5;
            diceNum[5] = d6;
            diceNum[6] = d2;
            diceNum[2] = d1;
            break;
    }
}

int main() {
    FAST_IO

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    dice = {1, 1, 0};

    while (K--) {
        moveDice();
        getScore();
        changeDiceStatus();
        changeDir();
    }
    cout << answer;
    return 0;
}


