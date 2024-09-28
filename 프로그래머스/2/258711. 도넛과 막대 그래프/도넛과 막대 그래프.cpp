#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 1000005
using namespace std;

int in_edge[MAX]; // 들어오는 간선의 개수
int out_edge[MAX]; // 나가는 간선의 개수
vector<int> graph[MAX]; // 그래프

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    for (auto edge : edges) {
        in_edge[edge[1]]++;
        out_edge[edge[0]]++;
        graph[edge[0]].push_back(edge[1]);
    }
        
    for (int i = 1; i < MAX; i++) {
        // 생성된 정점은 나가는 간선이 2개 이상 존재하고, 들어오는 간선은 없다.
        if (in_edge[i] == 0 && out_edge[i] >= 2) {
            answer.push_back(i);
        }
    }
    
    // 최대 값은 250,000개
    vector<int> v = graph[answer[0]];
    
    int cnt1 = 0; // 도넛
    int cnt2 = 0; // 막대
    int cnt3 = 0; // 8자
    
    for (int i = 0; i < v.size(); i++) {
        queue<int> q;
        q.push(v[i]);
        int depth = 1;
        bool is_stick_graph = true;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            
            // 8자 모양 그래프중 단 한개의 정점은 나가는 간선을 두 개 가진다.
            if (graph[now].size() >= 2) {
                cnt3++;
                is_stick_graph = false;
                break;
            }
            
            // 도넛 모양 그래프는 시작점으로 돌아온다.
            if (depth != 1 && now == v[i]) {
                cnt1++;
                is_stick_graph = false;
                break;
            }
            
            for (int j = 0; j < graph[now].size(); j++) {
                q.push(graph[now][j]);
            }
            depth++;
        }
        
        if (is_stick_graph) cnt2++;
    }                            
    answer.push_back(cnt1);
    answer.push_back(cnt2);
    answer.push_back(cnt3);
    
    return answer;
}