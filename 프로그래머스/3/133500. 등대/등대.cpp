#include <string>
#include <vector>

using namespace std;
bool light[100001];
vector<int> graph[100001];
int answer = 0;
void dfs(int node, int parent){
    for(int i = 0; i < graph[node].size(); i++){
        if(graph[node][i] != parent){
            dfs(graph[node][i], node);
            if(light[graph[node][i]] == false && light[node] == false){
                light[node] = true;
                answer++;
            }
        }
    }
}
int solution(int n, vector<vector<int>> lighthouse) {
    
    for(int i = 0; i < lighthouse.size(); i++){
        int v1 = lighthouse[i][0];
        int v2 = lighthouse[i][1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    dfs(1,1);
    return answer;
}