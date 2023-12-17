/*
3. 아방가르드 타일링 https://school.programmers.co.kr/learn/courses/30/lessons/181186
- 1 <= n <= 100_000 이므로 모든 경우의 수 탐색은 시간초과 -> DP로 풀어야 함
- 새로운 타일의 개수는 다음과 같다.
- n이 1일 때 1개
- n이 2일 때 2개
- n이 3일 때 5개
- 이전 것과 연관없이 한번에 덮는 타일은
- n이 4일 때 2개
- n이 5일 때 2개
- n이 6일 때 4개
- 7부터 (n - 3)에  1x3 가로 블럭을 추가하는 방법으로 2개
 */
public class Solution {
    static final long MOD = 1_000_000_007L;
    static final int N = 100_000;
    static long[] dp;
    // 추가적인 타일의 개수
    static long[] additional;

    public int solution(int n) {
        dp = new long[N + 1];
        additional = new long[N + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 3;
        dp[3] = 10;
        additional[4] = 2;
        additional[5] = 4;
        for (int i = 4; i <= n; i++) {
            dp[i] = (dp[i] + dp[i - 1] + (dp[i - 2] * 2) + (dp[i - 3] * 5)) % MOD;
            if (i >= 6) {
                additional[i] = (2 * dp[i - 4] + 2 * dp[i - 5] + 4 * dp[i - 6] + additional[i - 3]) % MOD;
            }
            dp[i] = (dp[i] + additional[i]) % MOD;
            dp[i] %= MOD;
        }

        return (int) dp[n];
    }
}
