#include <string>
#include <vector>

using namespace std;

#define MAX 100001
const int mod = 10007;

int dp[2 * MAX + 1]; // i번째 위치에 삼각형이 추가 될 때, 만들 수 있는 경우의 수
int solution(int n, vector<int> tops) {
    int answer = 0;    
    dp[0] = 1;
    dp[1] = 1;
    if (tops[0] == 1) {
        dp[2] = dp[1] + 2;
    } else {
        dp[2] = dp[1] + 1;
    }
    
    // 1: 삼각형, 2: / 마름모, 3: \ 마름모, 4. <> 마름모
    // i가 홀수 번째 인 경우, i-2 번째에 2번 마름모 추가와 i-1번재에서 삼각형 하나 추가하는 경우만 있다
    // i가 짝수 번째이고 위가 없는 경우, 홀수와 동일
    // i가 짝수 번째이고 위가 있는 경우, i-2 번째에 2번 마름모 추가와 삼각형1개, 삼각형1개 4번마름모추가, 전부 삼각형
    // i-1 번쨰에 4번 마름모 추가, 전부 삼각형
    // -> i-2번째의 삼각형1개 4번마름모는 i-1번째 4번마름모 추가와 동일
    // -> i-2번째 전부 삼각형은 i-1번째 전부삼각형과 동일
    // i가 홀수, dp[i] = dp[i-1] + dp[i-2]
    // i가 짝수이고 위가 없는 경우 dp[i] = dp[i-1] + dp[i-2]
    // i가 짝수이고 위가 있는 경우 dp[i] = 2 * dp[i-1] + dp[i-2]
    for (int i = 3; i <= 2*n + 1; i++) {
        if (i % 2 != 0) dp[i] = (dp[i-1] + dp[i-2]) % mod;
        else {
            // 2 -> 0, 4 -> 1, 6 -> 2
            if (tops[i/2 -1] == 1) dp[i] = (2 * dp[i-1] + dp[i-2]) % mod;
            else dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
    }
    return dp[2*n + 1];
}