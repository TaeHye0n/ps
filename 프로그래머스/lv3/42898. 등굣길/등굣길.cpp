#include <string>
#include <vector>
#define MAX 101
using namespace std;

int dp[MAX][MAX];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    dp[1][1] = 1;
    for(vector<int> puddle : puddles){
        dp[puddle[1]][puddle[0]] = -1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j =1; j <=m; j++){
            if(dp[i][j] == -1) continue;
            pair<int,int> temp;
            if(dp[i-1][j] != -1) temp.first = dp[i-1][j];
            if(dp[i][j-1] != -1) temp.second = dp[i][j-1];
            dp[i][j] += (temp.first + temp.second) % 1000000007;
        }
    }
    return dp[n][m];
}