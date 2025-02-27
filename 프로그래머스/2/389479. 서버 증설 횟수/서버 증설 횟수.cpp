#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q;
    for (int i = 0; i < players.size(); i++) {
        while (!q.empty() && q.front() <= i) {
            q.pop();
        }
        
        int req_server = players[i] / m;
        
        if (req_server > q.size()) {
            int need = req_server - q.size();
            answer += need;
            
            while (need--) {
                q.push(i + k);
            }
        }
    }
    return answer;
}