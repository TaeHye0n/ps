#include <string>
#include <vector>
#include <queue>
using namespace std;

int dist[20001];
vector<int> line[50001];
bool vi[20001];
queue<int> q;
int temp;

void bfs(){
    q.push(1);
    vi[1] = true;
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(int i = 0;i < line[current].size() ; i++){
            int next = line[current][i];
            if(vi[next] == false){
                q.push(next);
                vi[next] = true;
                dist[next] = dist[current] + 1;
                temp = max(temp, dist[next]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0; i <edge.size() ; i++){
        int from = edge[i][0];
        int to = edge[i][1];
        line[from].push_back(to);
        line[to].push_back(from);
    }     
    bfs();
    
    for(int i = 1; i <= n ; i++){
        if(dist[i] == temp) answer++;
    }
    return answer;
}