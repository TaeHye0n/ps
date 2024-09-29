#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Y first
#define X second
#define endl "\n"

#define MAX 21
using namespace std;
typedef long long ll;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
struct group {
    int cnt;
    int rainbow_cnt;
    int y;
    int x;
    vector<pair<int, int>> blocks;
};
int board[MAX][MAX];
int N, M;

bool cmp(group &g1, group &g2) {
    if (g1.cnt == g2.cnt) {
        if (g1.rainbow_cnt == g2.rainbow_cnt) {
            if (g1.y == g2.y) {
                return g1.x > g2.x;
            }
            return g1.y > g2.y;
        }
        return g1.rainbow_cnt > g2.rainbow_cnt;
    }
    return g1.cnt > g2.cnt;
}

void do_gravity() {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            // 검은색이거나 빈칸인 경우 패스
            if (board[i][j] == -1 || board[i][j] == -2) continue;

            int ny = i;
            while (1) {
                ny += dy[0];

                if (ny >= N || board[ny][j] != -2) break;
            }
            ny--;
            if (ny == i) continue;
            int temp = board[i][j];
            board[ny][j] = temp;
            board[i][j] = -2;
        }
    }
}

void rotate_counterclockwise() {
    int temp[MAX][MAX];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = board[j][N - 1 - i];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = temp[i][j];
        }
    }

}

int main() {
    FAST_IO;
    cin >> N >> M;

    int score = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    while (1) {
        bool visited[MAX][MAX] = {false,};
        vector<group> groups;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] >= 1 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    visited[i][j] = true;
                    bool rainbow_visited[MAX][MAX] = {false,};
                    q.push({i, j});
                    int cnt = 1, rainbow_cnt = 0;
                    vector<pair<int, int>> blocks;
                    blocks.push_back({i, j});
                    int minY = i;
                    int minX = j;

                    while (!q.empty()) {
                        int cy = q.front().Y;
                        int cx = q.front().X;
                        q.pop();

                        for (int w = 0; w < 4; w++) {
                            int ny = cy + dy[w];
                            int nx = cx + dx[w];

                            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                            if (board[ny][nx] == -1) continue;

                            if (visited[ny][nx]) continue;

                            // 방문하지 않은 무지개 블록
                            if (!rainbow_visited[ny][nx] && board[ny][nx] == 0) {
                                rainbow_visited[ny][nx] = true;
                                rainbow_cnt++;
                                cnt++;
                                q.push({ny, nx});
                                blocks.push_back({ny, nx});
                                continue;
                            }

                            // 같은 색 블록
                            if (board[ny][nx] == board[i][j]) {
                                visited[ny][nx] = true;
                                cnt++;
                                q.push({ny, nx});
                                blocks.push_back({ny, nx});

                                if (minY > ny) {
                                    minY = ny;
                                    minX = nx;
                                } else if (minY == ny && minX > nx) {
                                    minX = nx;
                                }
                            }
                        }
                    }
                    if (cnt < 2) continue;
                    groups.push_back({cnt, rainbow_cnt, minY, minX, blocks});
                }
            }
        }

        if (groups.empty()) {
            break;
        }
        sort(groups.begin(), groups.end(), cmp);
        // 2 모든 블록 제거
        group g = groups.front();
        vector<pair<int, int>> blocks = g.blocks;
        score += (g.cnt * g.cnt);
        for (int i = 0; i < blocks.size(); i++) {
            board[blocks[i].Y][blocks[i].X] = -2; // -2는 빈칸
        }

        // 3. 중력
        do_gravity();

        // 4. 90도 반시계 회전
        rotate_counterclockwise();

        // 5. 중력
        do_gravity();
    }
    cout << score;

    return 0;
}

