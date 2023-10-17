import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static final int MOD = 1000000;
    static int[][][] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dp = new int[2][3][N + 1];
        dp[0][0][1] = 1;
        dp[0][1][1] = 1;
        dp[1][0][1] = 1;

        for (int i = 2; i <= N; i++) {
            dp[0][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1]) % MOD;
            dp[0][1][i] = dp[0][0][i - 1] % MOD;
            dp[0][2][i] = dp[0][1][i - 1] % MOD;
            dp[1][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1] +
                    dp[1][0][i - 1] + dp[1][1][i - 1] + dp[1][2][i - 1]) % MOD;
            dp[1][1][i] = dp[1][0][i - 1] % MOD;
            dp[1][2][i] = dp[1][1][i - 1] % MOD;
        }

        int answer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                answer = (answer + dp[i][j][N]) % MOD;
            }
        }
        System.out.println(answer);
    }
}