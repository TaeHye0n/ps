import java.io.*;
import java.util.*;

public class Main {
    static long answer;
    static long dp[][][];
    static final long MOD = 1_000_000_000L;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        answer = 0L;
        dp = new long[N+1][10][1<<10];

        for (int i = 1; i <= 9; i++) {
            dp[1][i][1<<i] = 1;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k < (1 << 10); k++) {
                    int bit = k | (1 << j);
                    if (j == 0) {
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i-1][j+1][k]) % MOD;
                    } else if (j == 9) {
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i-1][j-1][k]) % MOD;
                    } else {
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MOD;
                    }
                }
            }
        }

        for (int i = 0; i <= 9; i++) {
            answer = (answer + dp[N][i][(1 << 10) - 1]) % MOD;
        }
        System.out.println(answer);
    }
}