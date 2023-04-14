#include <iostream>
#include <vector>
using namespace std;

int dp[1000001];
int solution(vector<int> sticker)
{
    int answer = 0;
    int N = sticker.size();
    if(N == 1) return sticker[0];
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    for(int i = 2; i < N-1; i++){
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    answer = max(answer, dp[N-2]);
    
    dp[0] = 0;
    dp[1] = sticker[1];
    for(int i = 2; i < N; i++){
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    answer = max(answer, dp[N-1]);

    return answer;
}