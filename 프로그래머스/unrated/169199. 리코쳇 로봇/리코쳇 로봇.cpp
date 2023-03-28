// BFS
#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer;
int n,m;
queue<pair<int,int>> q;
int dist[101][101];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int solution(vector<string> board) {
    n = board.size();
    m = board[0].size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'R'){
                q.push({i,j});
                dist[i][j] = 1;
                break;
            }
        }
    }
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(board[y][x] == 'G'){
            return dist[y][x] - 1;
        }
        for(int w = 0; w < 4; w++){
            int ny = y;
            int nx = x;
            while(1){
                ny += dy[w];
                nx += dx[w];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m){
                    ny -= dy[w];
                    nx -= dx[w];
                    break;
                }
                if(ny >= 0 && nx >= 0 && ny < n && nx < m && board[ny][nx] == 'D'){
                    ny -= dy[w];
                    nx -= dx[w];
                    break;
                }
            }
            if(dist[ny][nx] == 0){
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    return -1;
}

// DFS
// #include <string>
// #include <vector>
// #include <climits>
// #include <iostream>
// using namespace std;

// int answer = INT_MAX;
// int dy[4] = {1,-1,0,0};
// int dx[4] = {0,0,1,-1};
// bool visited[101][101];
// int n, m;
// int count[101][101];

// void dfs(int cnt, int y, int x, int dir, vector<string> board){
//     if(board[y][x] == 'G'){
//         answer = min(cnt, answer);
//         return;
//     }
//     count[y][x] = min(count[y][x], cnt);
//     for(int w = 0; w < 4; w++){
//         if(cnt != 0 && w == dir) continue;
//         int ny = y;
//         int nx = x;
//         while(1){
//             ny = ny + dy[w];
//             nx = nx + dx[w];
//             if(nx < 0 || ny < 0 || nx >= m || ny >= n) {
//                     nx -= dx[w];
//                     ny -= dy[w];
//                     break;
//                 }
//             if(0 <= nx && nx < m && 0 <= ny && ny < n && board[ny][nx] == 'D'){
//                     nx -= dx[w];
//                     ny -= dy[w];
//                     break;
//                 }
//         }
//         if(board[ny][nx] == 'R' || visited[ny][nx]) continue;
//         if(count[ny][nx] <= cnt+1) continue;
//         // cout <<cnt << " " << w << " " << ny << " " << nx << "\n";
//         visited[ny][nx] = true;
//         dfs(cnt+1, ny, nx, w, board);
//         visited[ny][nx] = false;
//     }
// }

// int solution(vector<string> board) {
//     n = board.size();
//     m = board[0].size();
//     int y, x;
//     for(int i = 0; i < board.size(); i++){
//         for(int j = 0; j < board[0].size(); j++){
//             if(board[i][j] == 'R'){
//                 y = i;
//                 x = j;
//             }
//             count[i][j] = INT_MAX;
//         }
//     }
//     dfs(0, y, x, 0, board);
//     if(answer == INT_MAX) return -1;
//     return answer;
// }
