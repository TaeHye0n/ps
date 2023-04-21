#include <iostream>

#define MAX 301
using namespace std;


int main()
{
    int N; // 계단 의 수
    cin >> N;
    
    int stair[MAX] = {0, };
    for(int i = 1; i <= N; i++){
        cin >> stair[i];
    }
    
    int dp[MAX] = {0, }; //  DP ARRAY
    
    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3] , stair[2] + stair[3]);
    for(int i = 4; i <=N; i++){
        dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
    }
    
    cout << dp[N];

    return 0;
}