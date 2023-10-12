#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 21

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};
const int mdy[4][3] = {{-1, 0, 1}, {1, 0, -1}, {-1, -1, -1}, {1, 1, 1}};
const int mdx[4][3] = {{1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {1, 0, -1}};
int board[MAX][MAX];
bool isWall[MAX][MAX][4];

int R, C, K, W;

struct pos {
    int y;
    int x;
    int dir;
};

vector<pos> machines;
vector<pair<int, int>> checkPos;

void printArray() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void control() {
    int temp[MAX][MAX] = {0,};

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            for (int w = 0; w < 2; w++) {
                pair<int, int> minPos, maxPos;
                int dir = (w == 0) ? 0 : 3;
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if (ny <= 0 || nx <= 0 || ny > R || nx > C) continue;
                if (isWall[i][j][dir]) continue;

                if (board[i][j] > board[ny][nx]) {
                    maxPos = {i, j};
                    minPos = {ny, nx};
                } else if (board[i][j] < board[ny][nx]) {
                    maxPos = {ny, nx};
                    minPos = {i, j};
                }
                int dif = abs(board[i][j] - board[ny][nx]);
                dif /= 4;
                temp[maxPos.first][maxPos.second] -= dif;
                temp[minPos.first][minPos.second] += dif;
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            board[i][j] += temp[i][j];
        }
    }

    for (int i = 1; i <= C; i++) {
        if (board[1][i] > 0) board[1][i]--;
        if (board[R][i] > 0) board[R][i]--;
    }

    for (int i = 2; i < R; i++) {
        if (board[i][1] > 0) board[i][1]--;
        if (board[i][C] > 0) board[i][C]--;
    }
}

bool canPass(int y, int x, int dir, int ndir) {
    if (ndir == 1) {
        if (!isWall[y][x][dir]) return true;
    } else if (ndir == 0) {
        if (dir == 0) {
            if (!isWall[y][x][2] && !isWall[y - 1][x][0]) return true;
        } else if (dir == 1) {
            if (!isWall[y][x][3] && !isWall[y + 1][x][1]) return true;
        } else if (dir == 2) {
            if (!isWall[y][x][1] && !isWall[y][x - 1][2]) return true;
        } else {
            if (!isWall[y][x][0] && !isWall[y][x + 1][3]) return true;
        }
    } else {
        if (dir == 0) {
            if (!isWall[y][x][3] && !isWall[y + 1][x][0]) return true;
        } else if (dir == 1) {
            if (!isWall[y][x][2] && !isWall[y - 1][x][1]) return true;
        } else if (dir == 2) {
            if (!isWall[y][x][0] && !isWall[y][x + 1][2]) return true;
        } else {
            if (!isWall[y][x][1] && !isWall[y][x - 1][3]) return true;
        }
    }
    return false;
}


void spread() {
    for (int i = 0; i < machines.size(); i++) {
        queue<pair<pair<int, int>, int>> q;
        bool visited[MAX][MAX] = {false,};
        pos &cur = machines[i];
        int y = cur.y;
        int x = cur.x;
        int dir = cur.dir;
        q.push({{y + dy[dir], x + dx[dir]}, 5});

        while (!q.empty()) {
            int cy = q.front().first.first;
            int cx = q.front().first.second;
            int air = q.front().second;
            q.pop();

            board[cy][cx] += air;
            if (air == 1) continue;

            for (int w = 0; w < 3; w++) {
                int ny = cy + mdy[dir][w];
                int nx = cx + mdx[dir][w];
                if (ny <= 0 || nx <= 0 || ny > R || nx > C) continue;

                if (!visited[ny][nx] && canPass(cy, cx, dir, w)) {
                    visited[ny][nx] = true;
                    q.push({{ny, nx}, air - 1});
                }
            }
        }
    }
}

int main() {
    FAST_IO

    cin >> R >> C >> K;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            int input;
            cin >> input;
            if (input == 5) {
                checkPos.emplace_back(i, j);
            } else if (input != 0) {
                machines.push_back({i, j, input - 1});
            }
        }
    }

    cin >> W;

    for (int i = 0; i < W; i++) {
        int y, x, t;
        cin >> y >> x >> t;
        if (t == 0) {
            isWall[y][x][2] = true;
            isWall[y - 1][x][3] = true;
        } else {
            isWall[y][x][0] = true;
            isWall[y][x + 1][1] = true;
        }
    }

    int answer = 0;
    while (1) {
        spread();
        control();
        answer++;
//        printArray();
        bool flag = true;
        for (int i = 0; i < checkPos.size(); i++) {
            if (board[checkPos[i].first][checkPos[i].second] < K) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << answer;
            return 0;
        }

        if (answer > 100) {
            cout << 101;
            return 0;
        }
    }

}
