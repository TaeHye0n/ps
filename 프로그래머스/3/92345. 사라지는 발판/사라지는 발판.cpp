#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int n, m; // <= 5
vector<vector<int>> board;

bool can_move(int y, int x) {
    for (int w = 0; w < 4; w++) {
        int ny = y + dy[w];
        int nx = x + dx[w];
        
        if (ny >= 0 && nx >= 0 && ny < n && nx < m && board[ny][nx] == 1) return true;
    }
    return false;
}

pair<int, bool> move(int y, int x, int o_y, int o_x) {
    if (!can_move(y, x) || board[y][x] == 0) {
        return {0, false};
    }
    
    int min_move = 987654321;
    int max_move = 0;
    bool can_win = false;
    
    board[y][x] = 0;
    
    for (int w = 0; w < 4; w++) {
        int ny = y + dy[w];
        int nx = x + dx[w];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || board[ny][nx] == 0) continue;
        
        auto res = move(o_y, o_x, ny, nx);
        
        if (!res.second) {
            can_win = true;
            min_move = min(min_move, res.first + 1);
        } else {
            max_move = max(max_move, res.first + 1);
        }
    }
    
    board[y][x] = 1;
    
    if (can_win) {
        return {min_move, true};
    } else {
        return {max_move, false};
    }
    
}

int solution(vector<vector<int>> board_2, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    board = board_2;
    n = board.size();
    m = board[0].size();
    auto res = move(aloc[0], aloc[1], bloc[0], bloc[1]);
    return res.first;
}