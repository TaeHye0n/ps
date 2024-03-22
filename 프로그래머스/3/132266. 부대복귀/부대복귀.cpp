#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define INF 987654321
using namespace std;

int dist[100001];
vector<pair<int, int>> graph[100001];

void dijkstra(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
    dist[st] = 0;
    pq.push({0, st});
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (cost != dist[cur]) continue;
        
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i].first;
            int ncost = graph[cur][i].second;
            
            if (ncost + cost >= dist[nxt]) continue;
            dist[nxt] = ncost + cost;
            pq.push({dist[nxt], nxt});
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for (int i = 0; i < roads.size(); i++) {
        int from = roads[i][0];
        int to = roads[i][1];
        graph[from].push_back({to, 1});
        graph[to].push_back({from, 1});
    }
    
    for (int i = 1 ; i <= n; i++) {
        dist[i] = INF;
    }
    
    dijkstra(destination);
    
    for (auto st : sources) {
        if (dist[st] == INF) answer.push_back(-1);
        else answer.push_back(dist[st]);
    }
    
    return answer;
}