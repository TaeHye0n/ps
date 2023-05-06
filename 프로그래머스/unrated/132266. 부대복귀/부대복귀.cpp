#include <string>
#include <vector>
#include <queue>

#define MAX 100001
#define INF 987654321
using namespace std;

int dist[MAX];
vector<pair<int,int>> graph[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0,start});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cost > dist[cur]) continue;
        
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int ncost = graph[cur][i].second;
            
            if(dist[next] > cost+ncost){
                dist[next] = cost + ncost;
                pq.push({cost+ncost, next});
            }
        }
    }
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(int i = 0; i < roads.size(); i++){
        int v1 = roads[i][0];
        int v2 = roads[i][1];
        graph[v1].push_back({v2,1});
        graph[v2].push_back({v1,1});
    }
    
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }
    
    dijkstra(destination);
    
    for(int i = 0; i < sources.size(); i++){
        int vertex = sources[i];
        if(dist[vertex] == INF) answer.push_back(-1);
        else answer.push_back(dist[vertex]);
    }
    return answer;
}