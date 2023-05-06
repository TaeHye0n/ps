#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int ans=0;
    bool dp[2501][2501] = {false, };
    int N = s.size();
    
    for(int i = 0; i < N; i++){
        dp[i][i] = true;
        if(i >= 1 && s[i-1] == s[i]){
            dp[i-1][i] = true;
        }
    }
    
    for(int i = N-3; i >=0 ; i--){
        for(int j = i+2; j< N; j++){
            if(s[i]==s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                ans = max(ans,j-i+1);
            }
        }
    }
  
    if(ans==0) return 1;
    return ans;
}