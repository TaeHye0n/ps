#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define first Y
#define second X
#define endl "\n"

#define MAX 51
using namespace std;
typedef long long ll;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

struct virus {
    int y;
    int x;
};
vector<virus> v, comb;
int N; // 연구소의 크기 4 <= N <= 50
int M; // 놓을 수 있는 바이러스의 개수 1 <= M <= 10
int lab[MAX][MAX];
int visited[MAX][MAX];
int ans = INT_MAX;

void bfs() {
    memset(visited, -1, sizeof(visited));
    queue<virus> q;

    for (auto e: comb) {
        q.push(e);
        visited[e.y][e.x] = 0;
    }

    while (!q.empty()) {
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        for (int w = 0; w < 4; w++) {
            int ny = cy + dy[w];
            int nx = cx + dx[w];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

            if (visited[ny][nx] != -1 || lab[ny][nx] == 1) continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    bool all_spread = true;
    int spread_time = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lab[i][j] == 0) {
                if (visited[i][j] == -1) {
                    all_spread = false;
                    break;
                }
                spread_time = max(spread_time, visited[i][j]);
            }
        }
    }

    if (all_spread) ans = min(ans, spread_time);
}

void make_comb(int idx, int cnt) {
    if (cnt == M) {
        bfs();
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        comb.push_back(v[i]);
        make_comb(i + 1, cnt + 1);
        comb.pop_back();
    }
}

int main() {
    FAST_IO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) v.push_back({i, j});
        }
    }

    make_comb(0, 0);
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}

