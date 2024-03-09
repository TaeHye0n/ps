#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};


struct node {
    int y;
    int x;
    int pay;
    int dir;
    
};

struct cmp {
    bool operator()(node n1, node n2) {
        return n1.pay > n2.pay;
    }
};

int cost[4][26][26];


int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    int n = board.size();
    priority_queue<node, vector<node>, cmp> q;
    q.push({0, 0, 0, 0});
    q.push({0, 0, 0, 1});
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cost[i][j][k] = INT_MAX;
            }
        }
    }
    
    
    while (!q.empty()) {
        int y = q.top().y;
        int x = q.top().x;
        int pay = q.top().pay;
        int dir = q.top().dir;
        q.pop();
        
        if (y == n - 1 && x == n - 1) {
            answer = min(answer, cost[dir][y][x]);
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            
            if (board[ny][nx] == 1) continue;
        
            int npay = 0;
            if (dir == i) npay = pay + 100;
            else npay = pay + 600;
            
            if (cost[i][ny][nx] >= npay) {
                q.push({ny, nx, npay, i});
                cost[i][ny][nx] = npay;
            }        
        }
    }
    return answer;
}