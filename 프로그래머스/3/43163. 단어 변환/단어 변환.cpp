#include <string>
#include <vector>
#include <climits>
using namespace std;
bool visited[51];
int answer = INT_MAX;


void dfs(string cur, string target, int count, vector<string> words) {
    if (target == cur) {
        answer = min(answer, count);
        return;
    }
    
    for (int i = 0; i < words.size(); i++) {
        int charCount = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] != cur[j]) charCount++;
            if (charCount >= 2) break;
        }
        if (charCount == 1) {
            if (!visited[i]) {
                 visited[i] = true;
                 dfs(words[i], target, count + 1, words);
                 visited[i] = false;
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    
    dfs(begin, target, 0, words);
    return answer == INT_MAX ? 0 : answer;
}