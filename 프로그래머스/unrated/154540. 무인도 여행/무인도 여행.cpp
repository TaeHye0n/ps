#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool visited[101][101];

queue<pair<int,int>> q;

int bfs(vector<string> maps, int i, int j){
    q.push({i,j});
    int cnt = maps[i][j] - '0';
    visited[i][j] = true;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int w = 0; w < 4; w++){
            int ny = y + dy[w];
            int nx = x + dx[w];
            
            if(ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
            
            if(maps[ny][nx] != 'X' && !visited[ny][nx]){
                cnt += maps[ny][nx] - '0';
                q.push({ny,nx});
                visited[ny][nx] = true;
            }
        }
    }
    return cnt;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(maps[i][j] != 'X' && !visited[i][j]){
                answer.push_back(bfs(maps,i,j));
            }
        }
    }
    
    if(answer.empty()) answer.push_back(-1);
    else{
        sort(answer.begin(),answer.end());
    }
    return answer;
}