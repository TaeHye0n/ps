#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int visited[101][101];
bool isPulled = false;
bool isEscapable = false;
queue<pair<int,int>> q;
int answer = -1;

void bfs1(vector<string> maps){
    int m = maps.size();
    int n = maps[0].length();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(maps[i][j] == 'S'){
                q.push({i,j});
                break;
            }
        }
    }
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            
            if(visited[ny][nx] == 0 && (maps[ny][nx] == 'O' || maps[ny][nx] == 'E')){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
            else if(visited[ny][nx] == 0 && maps[ny][nx] == 'L'){
                visited[ny][nx] = visited[y][x] + 1;
                while(!q.empty()){
                    q.pop();
                }
                q.push({ny,nx});
                isPulled = true;
                answer = visited[ny][nx];
                return;
            }
        }
    }
}

void bfs2(vector<string> maps){
    int m = maps.size();
    int n = maps[0].length();
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            
            if(visited[ny][nx] == 0){
                if(maps[ny][nx] == 'S' || maps[ny][nx] == 'O'){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny,nx});
                }
                if(maps[ny][nx] == 'E'){
                    visited[ny][nx] = visited[y][x] + 1;
                    answer += visited[ny][nx];
                    isEscapable = true;
                    return;
                }
            }
        }
    }
}

int solution(vector<string> maps) {
    bfs1(maps);
    if(!isPulled) return answer;
    else{
        bfs2(maps);
        if(!isEscapable) return -1;
        return answer;
    }
}

