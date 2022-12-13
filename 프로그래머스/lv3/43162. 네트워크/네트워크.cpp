#include <string>
#include <vector>

using namespace std;

bool vi[201];
int answer = 0;

void dfs(int x, int n, vector<vector<int>> computers){
     vi[x] = true;
    
    for(int i = 0; i < n; i++){
        if(vi[i] == false && computers[x][i] == 1) {
            dfs(i, n , computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for(int i = 0; i < n; i++){
        if(vi[i] == false){
           dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}