#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;
queue<int> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) {
        q.push(i);
        pq.push(priorities[i]);
    }
    
    int order = 0;
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        if (pq.top() > priorities[idx]) {
            q.push(idx);
        } else {
            pq.pop();
            order++;
            if (idx == location) return order;
        }
    }
    return answer;
}