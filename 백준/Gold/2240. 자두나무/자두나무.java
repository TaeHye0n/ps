import java.io.*;
import java.util.*;

public class Main {
    static int T; //자두는 T초 동안 떨어진다
    static int W; //움직이는 최대 횟수
    static int[][][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        dp = new int[3][T+1][W+1];

        for (int i = 1; i <= T; i++) {
            int pos = Integer.parseInt(br.readLine());
            for (int j = 0; j <= W; j++) {
                if (pos == 1) {
                    if (j == 0) {
                        dp[1][i][j] = dp[1][i - 1][j] + 1;
                        continue;
                    }
                    dp[1][i][j] = Math.max(dp[1][i - 1][j], dp[2][i - 1][j - 1]) + 1;
                    dp[2][i][j] = Math.max(dp[2][i - 1][j], dp[1][i - 1][j - 1]);
                } else {
                    if (j == 0) {
                        dp[1][i][j] = dp[1][i-1][j];
                        continue;
                    }
                    dp[1][i][j] = Math.max(dp[1][i-1][j], dp[2][i-1][j-1]);
                    dp[2][i][j] = Math.max(dp[1][i-1][j-1], dp[2][i-1][j]) + 1;
                }
            }
        }
        int answer = 0;
        for (int i = 0; i <= W; i++) {
            answer = Math.max(answer, Math.max(dp[1][T][i], dp[2][T][i]));
        }
        System.out.println(answer);
    }
}