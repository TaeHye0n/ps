class Solution {
    static final int MOD = 1000000007;
    public int solution(int n, int[] money) {
        int answer = 0;
        
        int[] dp = new int[n + 1];
        dp[0] = 1;
        
        for (int i = 0; i < money.length; i++) {
            for (int j = money[i]; j <= n; j++) {
                dp[j] = (dp[j] + dp[j - money[i]]) % MOD;
            }
        }
        return dp[n];
    }
}