#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 11
#define INF 987654321

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int N, M;
int answer = INF;

struct pos {
    int y;
    int x;
};

char board[MAX][MAX];

pos red, blue;

void move(int ry, int rx, int by, int bx, int dir, int cnt) {
    if (cnt >= answer || cnt > 10) return;

    bool isRedIn = false;
    bool isBlueIn = false;

    int nry = ry + dy[dir];
    int nrx = rx + dx[dir];

    int nby = by + dy[dir];
    int nbx = bx + dx[dir];

    while (true) {
        if (board[nry][nrx] == '#') break;
        if (board[nry][nrx] == 'O') {
            isRedIn = true;
            break;
        }
        nry += dy[dir];
        nrx += dx[dir];
    }
    nry -= dy[dir];
    nrx -= dx[dir];

    while (true) {
        if (board[nby][nbx] == '#') break;
        if (board[nby][nbx] == 'O') {
            isBlueIn = true;
            break;
        }
        nby += dy[dir];
        nbx += dx[dir];
    }
    nby -= dy[dir];
    nbx -= dx[dir];

    if (isBlueIn) return;
    else {
        if (isRedIn) {
            answer = min(answer, cnt);
            return;
        }
    }

    if (nry == nby && nrx == nbx) {
        int redDist = abs(ry - nry) + abs(rx - nrx);
        int blueDist = abs(by - nby) + abs(bx - nbx);

        if (redDist > blueDist) {
            nry -= dy[dir];
            nrx -= dx[dir];
        } else {
            nby -= dy[dir];
            nbx -= dx[dir];
        }
    }

    for (int w = 0; w < 4; w++) {
        if (w == dir) continue;
        if (w == ((dir + 2) % 4)) continue;

        move(nry, nrx, nby, nbx, w, cnt + 1);
    }
}

int main() {
    FAST_IO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            } else if (board[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        move(red.y, red.x, blue.y, blue.x, i, 1);
    }

    if (answer > 10 || answer == INF) {
        cout << -1;
        return 0;
    }
    cout << answer;
    return 0;
}
