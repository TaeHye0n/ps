#include <string>
#include <vector>
#include <queue>
using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    queue<int> q;
    q.push(x);
    for(int i = 0; i < 1000001; i++){
        dp[i] = -1;
    }
    dp[x] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : {curr + n, curr * 2, curr * 3}){
            if(next > y) continue;
            if(dp[next] != -1) continue;
            dp[next] = dp[curr] + 1;
            q.push(next);
        }
    }
    return dp[y];
}