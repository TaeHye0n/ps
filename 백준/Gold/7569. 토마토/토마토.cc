#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second
using namespace std;
typedef long long ll;

int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, 1, -1, 0,0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int n, m, h; // 세로 가로 높이
int board[101][101][101]; // h, n, m
bool visited[101][101][101];

struct pos {
    int z;
    int y;
    int x;
};

int main() {
    FAST_IO;
    
    cin >> m >> n >> h;
    vector<pos> v;
    
    bool flag = true;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    v.push_back({ i, j, k });
                }
                else if (board[i][j][k] == 0) {
                    flag = false;
                }
            }
        }
    }

    if (flag) {
        cout << 0;
        return 0;
    }

    int ans = -1;
    while (!v.empty()) {
        ans++;
        queue<pos> q;
        vector<pos> v2;
        for (auto p : v) {
            q.push(p);
        }

        while (!q.empty()) {
            int cz = q.front().z;
            int cy = q.front().y;
            int cx = q.front().x;
            q.pop();

            for (int w = 0; w < 6; w++) {
                int nz = cz + dz[w];
                int ny = cy + dy[w];
                int nx = cx + dx[w];

                if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) continue;

                if (visited[nz][ny][nx] || board[nz][ny][nx] != 0) continue;

                v2.push_back({ nz, ny, nx });
                visited[nz][ny][nx] = true;
                board[nz][ny][nx] = 1;
            }
        }

        v = v2;

    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (board[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << ans;

    return 0;
}