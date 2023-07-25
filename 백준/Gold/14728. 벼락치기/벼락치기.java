import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int[] k = new int[N+1];
        int[] s = new int[N+1];
        int[][] dp = new int[N+1][T+1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            k[i] = Integer.parseInt(st.nextToken());
            s[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= T; j++) {
                if (j - k[i] >= 0) {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j - k[i]] + s[i]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        System.out.println(dp[N][T]);
    }
}