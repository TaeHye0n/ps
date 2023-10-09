#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
#define MAX 21

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int N, M;
int F;
int board[MAX][MAX];
int visited[MAX][MAX];
int stY, stX;
int destY, destX;
bool flag = false;

struct customer {
    int y;
    int x;
    int destY;
    int dsetX;
};

vector<customer> v;

void findCustomer() {
    memset(visited, 0, sizeof(visited));
    visited[stY][stX] = 1;
    queue<pair<int, int>> q;
    q.push({stY, stX});
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int w = 0; w < 4; w++) {
            int ny = y + dy[w];
            int nx = x + dx[w];
            
            if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;

            if (visited[ny][nx] == 0 && board[ny][nx] == 0) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
    
    int dist = INF;
    int my = 0, mx = 0, idx = -1;
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].y;
        int x = v[i].x;
        if (visited[y][x] < dist) {
            my = y;
            mx = x;
            idx = i;
            dist = visited[y][x];
        } else if (visited[y][x] == dist) {
            if (y < my) {
                my = y;
                mx = x;
                idx = i;
            } else if (y == my && x < mx) {
                mx = x;
                idx = i;
            }
        }
    }
    F -= (dist - 1);
    stY = my; stX = mx;
    destY = v[idx].destY;
    destX = v[idx].dsetX;
    v.erase(v.begin() + idx);
    if (visited[my][mx] == 0) {
        flag = true;
    }
    if (F <= 0) {
        flag = true;
    }
}

void calDestinationDist() {
    memset(visited, 0, sizeof(visited));
    visited[stY][stX] = 1;
    queue<pair<int, int>> q;
    q.push({stY, stX});
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        if (y == destY && x == destX) break;
        q.pop();
        
        for (int w = 0; w < 4; w++) {
            int ny = y + dy[w];
            int nx = x + dx[w];
            
            if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
            
            if (visited[ny][nx] == 0 && board[ny][nx] == 0) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
}

int main() {
    FAST_IO;
    
    cin >> N >> M >> F;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    
    cin >> stY >> stX;
    
    for (int i = 0; i < M; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v.push_back({a, b, c, d});
    }
    
    while(v.size() != 0) {
        findCustomer();
        if (flag) {
            cout << -1;
            return 0;
        }
        calDestinationDist();
        if (visited[destY][destX] == 0) {
            cout << -1;
            return 0;
        }
        stY = destY; stX = destX;
        F -= (visited[destY][destX] - 1);
        if (F < 0) {
            cout << -1;
            return 0;
        }
        F += ((visited[destY][destX] - 1) * 2);
    }
    cout << F;
}
