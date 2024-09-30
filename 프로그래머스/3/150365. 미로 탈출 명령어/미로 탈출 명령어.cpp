#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// d, l, r, u 순서 (사전순을 고려한 탐색 순서)
const int dy[4] = {1, 0, 0, -1};
const int dx[4] = {0, -1, 1, 0};
const string dir[4] = {"d", "l", "r", "u"};
int st_y, st_x, ed_y, ed_x;
int n, m, k;
int dist;
bool found = false;
string answer;
bool visited[51][51][2501];

int cal_dist(int r1, int c1, int r2, int c2) {
    return abs(r2 - r1) + abs(c2 - c1);
}

void dfs(int y, int x, int remain, string path) {
    if (found) return; 
    
    if (cal_dist(y, x, ed_y, ed_x) > remain) return;

    if (remain == 0) {
        if (y == ed_y && x == ed_x) {
            found = true;
            answer = path;
        }
        return;
    }

    if (visited[y][x][remain]) return;
        visited[y][x][remain] = true;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny <= 0 || nx <= 0 || ny > n || nx > m) continue;

        if (found) return;
        dfs(ny, nx, remain - 1, path + dir[i]);
    }
}

string solution(int n1, int m1, int x, int y, int r, int c, int k1) {
    st_y = x; st_x = y; ed_y = r; ed_x = c;
    n = n1; m = m1; k = k1;
    dist = cal_dist(x, y, r, c);


    dfs(x, y, k, "");
    return found ? answer : "impossible";
}