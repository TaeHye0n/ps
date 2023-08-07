import java.io.*;
import java.util.*;

public class Main {
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[] dp = new int[N+1];
        Arrays.fill(dp, Integer.MAX_VALUE / 2);
        dp[0] = 0;

        for (int i = 2; i <= N; i++) {
            dp[i] = Math.min(dp[i-2] + 1, dp[i]);
            if (i - 5 >= 0) {
                dp[i] = Math.min(dp[i-5] + 1, dp[i]);
            }
        }

        if (dp[N] == Integer.MAX_VALUE / 2) System.out.println(-1);
        else System.out.println(dp[N]);
    }
}