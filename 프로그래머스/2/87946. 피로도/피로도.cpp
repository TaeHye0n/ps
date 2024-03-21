#include <string>
#include <vector>

using namespace std;
vector<vector<int>> dungeons;
int answer = 0;
bool visited[9];

void dfs(int cur, int cnt) {
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] || dungeons[i][0] > cur) continue;
        
        visited[i] = true;
        dfs(cur - dungeons[i][1], cnt + 1);
        visited[i] = false;
    }
    
    answer = max(answer, cnt);
    return;
}
int solution(int k, vector<vector<int>> dungeon) {
    dungeons = dungeon;
    dfs(k, 0);
    return answer;
}