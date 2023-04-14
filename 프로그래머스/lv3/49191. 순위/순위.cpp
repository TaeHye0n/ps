#include <string>
#include <vector>

using namespace std;
bool graph[101][101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(vector<int> v : results){
        graph[v[0]][v[1]] = true;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][k] && graph[k][j]) graph[i][j] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(graph[i][j] || graph[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    return answer;
}