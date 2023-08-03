import java.io.*;
import java.util.*;

public class Main {
    static int T;
    static int max;
    static long[] dp;
    static int[] input;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        input = new int[T];
        max = 0;

        for (int i = 0; i < T; i++) {
            input[i] = Integer.parseInt(br.readLine());
            max = Math.max(max, input[i]);
        }

        dp = new long[max+1];

        dp[0] = dp[1] = dp[2] = dp[3] = 1;

        for (int i = 4; i <= max; i++) {
            dp[i] = dp[i-2] + dp[i-3];
        }

        Arrays.stream(input).forEach(i -> sb.append(dp[i]).append("\n"));
        System.out.println(sb);

    }
}
