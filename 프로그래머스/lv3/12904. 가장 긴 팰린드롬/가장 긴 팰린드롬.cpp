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
    
    for(int i = 0; i < N; i++){
        for(int j = 0; i+j < N; j++){
            if(i == 0){
                ans = 1;
                break;
            }
            if(s[j] == s[j+i] && dp[j+1][i+j-1]){
                ans = max(ans,i+1);
                dp[j][i+j] = true;
            }
        }
    } 
  

    return ans;
}