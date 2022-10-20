#include <string>
#include <vector>
#include <cstring>

using namespace std;
bool vi[6][6];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

bool dfs(vector<string> places,int y, int x, int cnt){
    if(cnt == 3) return true;
    if(cnt > 0 && places[y][x] == 'P') return false;
    
    for(int w = 0; w < 4; w++){
        int ny = y + dy[w];
        int nx = x + dx[w];
        
        if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
        if(vi[ny][nx] == false && places[ny][nx] != 'X'){
            vi[ny][nx] = true;
            if(!dfs(places, ny,nx,cnt+1)) return false;
            vi[ny][nx] = false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i< 5; i++){
        bool flag = true;
        for(int j = 0; j < 5; j++){
           for(int k = 0; k < 5; k++){
               if(places[i][j][k] == 'P'){
                   memset(vi,false,sizeof(vi));
                   vi[j][k] = true;
                   if(!dfs(places[i], j, k, 0)){
                       flag = false;
                       break;
                   }
               }
           }
        }
        answer.push_back(flag);
    }
    return answer;
}