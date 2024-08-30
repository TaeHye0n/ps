#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int visited[8][8];

double calDist(int y1, int x1, int y2, int x2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    queue<pair<int, int>> q;
    q.push({h, w});
    visited[h][w] = 1;
    string color = board[h][w];
    
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();        
        
        for (int d = 0; d < 4; d++) {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            
            if (visited[ny][nx] != 0) continue;
            
            double dist = calDist(h, w, ny, nx);
            
            if (dist > 1) continue;
            if (board[ny][nx] == color) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
                answer++;
            }
        }
    }
    return answer;
}