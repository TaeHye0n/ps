#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int n = park.size();
    int m = park[0].size();
    int dp[51][51] = {0, };
    dp[0][0] = 1;
    int maxval = 0;
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (park[i][j] == "-1") {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
                maxval = max(maxval, dp[i][j]);
            }
        }
    }
    sort(mats.begin(), mats.end(), greater<>());
    for (auto mat : mats) {
        if (maxval >= mat) {
            answer = mat;
            break;
        }
    }
    
    return answer;
}