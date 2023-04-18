#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int dy[8] = { 1,-1,0,0,1,1,-1,-1 };
const int dx[8] = { 0,0,1,-1,1,-1,-1,1 };
int board[13][13];
int visited[13][13];
int n;
int answer;

void dfs(int num) {
    if (num == n) {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++) {
        int y = num;
        int x = i;
        bool flag = false;
        if (visited[y][x] != 0) continue;
        visited[y][x] = num + 1;
        for (int w = 0; w < 8; w++) {
            int ny = y;
            int nx = x;
            while (1) {
                ny += dy[w];
                nx += dx[w];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;

                if (visited[ny][nx] == 0) {
                    visited[ny][nx] = num + 1;
                }
            }
        }
        dfs(num + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == num + 1) {
                    visited[i][j] = 0;
                }
            }
        }
    }
}

int solution(int a) {
    n = a;

    dfs(0);
    return answer;
}
