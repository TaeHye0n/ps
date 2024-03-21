#include <string>
#include <vector>

#define MOD 1234567
using namespace std;
typedef long long ll;

long long solution(int n) {
    long long answer = 0;
    ll dp[2001];

    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
}