#include <string>
#include <vector>
#include <queue>
using namespace std;

struct word {
    string s;
    int depth;
};
bool visited[51];
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<word> q;
    q.push({begin, 0});
    
    while(!q.empty()) {
        word cur = q.front();
        q.pop();
        
        if (cur.s == target) {
            return cur.depth;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;
            int count = 0;
            for (int j = 0; j < words[i].size(); j++) {
                if (cur.s[j] != words[i][j]) count++;
                if (count >= 2) break;
            }
            
            if (count == 1) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push({words[i], cur.depth + 1});
                }
            }
        }
    }
    return answer;
}