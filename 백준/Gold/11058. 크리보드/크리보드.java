import java.io.*;
import java.util.*;

public class Main {
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        long[] dp = new long[N+1];
        for (int i = 1; i <= N; i++) {
            dp[i] = dp[i-1] + 1;
            for (int j = 1; j <= i-3; j++) {
                long temp = dp[i-(j+2)] * (j+1);
                dp[i] = Math.max(dp[i], temp);
            }
        }
        System.out.println(dp[N]);
    }
}