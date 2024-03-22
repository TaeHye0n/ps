#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 20001
using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
int dist[MAX];
queue<int> q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (int i = 0 ; i < edge.size(); i++) {
        int from = edge[i][0];
        int to = edge[i][1];
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    visited[1] = true;
    dist[1] = 0;
    q.push(1);
    int maxVal = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            
            if (visited[nxt]) continue;
            
            visited[nxt] = true;
            dist[nxt] = dist[cur] + 1;
            maxVal = max(maxVal, dist[nxt]);
            q.push(nxt);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == maxVal) {
            answer++;
        }
    }
    return answer;
}