#include <string>
#include <vector>
#define MAX 125

using namespace std;

const int INF = 987654321;

int dp[MAX][MAX];
int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int num = info.size();
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    
    
    for (int i = 0; i < num; i++) {
        int a_cost = info[i][0];
        int b_cost = info[i][1];
        
        for (int a = 0; a < n; a++) {
            int b_val = dp[i][a];
            if (b_val == INF) continue;
            
            if (a + a_cost < n) {
                dp[i + 1][a + a_cost] = min(dp[i + 1][a + a_cost], b_val);
            }
            
            if (b_val + b_cost < m) {
                dp[i + 1][a] = min(dp[i + 1][a], b_val + b_cost);
            }
        }
    }
    
    answer = INF;
    for (int i = 0; i < n; i++) {
        if (dp[num][i] < m) {
            answer = min(answer, i);
        }
    }
    return answer == INF ? -1 : answer;
}