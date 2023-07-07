import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] joy;
    static int[] loss;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        joy = new int[N+1];
        loss = new int[N+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            loss[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            joy[i] = Integer.parseInt(st.nextToken());
        }

        int[][] dp = new int[N+1][101];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= 100; j++) {
                if (j - loss[i] > 0) {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-loss[i]] + joy[i]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        System.out.println(dp[N][100]);
    }
}