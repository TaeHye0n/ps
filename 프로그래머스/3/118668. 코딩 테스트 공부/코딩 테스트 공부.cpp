#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

#define INF 987654321
using namespace std;


// 모든 문제들을 1번 이상씩 풀 필요는 없습니다.
// problems.size() <= 100
// 시간은 무조건 양수, max_알고, max_코딩까지 최단거리 구하기 -> 다익스트라
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    int dist[151][151];
    int max_alp = 0;
    int max_cop = 0;
    
    // 공부하는 노드와 간선 추가
    problems.push_back({0, 0, 1, 0, 1});
    problems.push_back({0, 0, 0, 1, 1});
    for (auto p : problems) {
        max_alp = max(max_alp, p[0]);
        max_cop = max(max_cop, p[1]);
    }
    
    for (int i = 0; i <= max_alp; i++) {
        for (int j = 0; j <= max_cop; j++) {
            dist[i][j] = INF;
        }
    }
        
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    dist[alp][cop] = 0;
    pq.push({0, alp, cop});
    
    while (!pq.empty()) {
        int cur_alp = 0, cur_cop = 0, cur_cost = 0;
        tie(cur_cost, cur_alp, cur_cop) = pq.top();
        pq.pop();
        
        if (dist[cur_alp][cur_cop] != cur_cost) continue;
        
        for (auto p : problems) {
            
            // 문제를 못 푸는 경우
            if (cur_alp < p[0] || cur_cop < p[1]) continue;
            
            // max_alp와 max_cop를 벗어나지 못하게 min 처리
            int next_alp = min(cur_alp + p[2], max_alp);
            int next_cop = min(cur_cop + p[3], max_cop);
            int next_cost = cur_cost + p[4];
            
            if (dist[next_alp][next_cop] <= next_cost) continue;
            dist[next_alp][next_cop] = next_cost;
            pq.push({next_cost, next_alp, next_cop});
        }
    }
    
    return dist[max_alp][max_cop];
}