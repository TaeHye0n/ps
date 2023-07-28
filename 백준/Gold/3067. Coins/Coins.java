import java.io.*;
import java.util.*;

public class Main {
    static int T;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");
            int[] coins = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
            int M = Integer.parseInt(br.readLine());
            solve(N, M, coins);
        }
        System.out.println(sb);
    }

    private static void solve(int n, int m, int[] coins) {
        int[] dp = new int[m+1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= m; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        sb.append(dp[m]).append("\n");
    }
}
