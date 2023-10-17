import java.util.*;
import java.io.*;

public class Main {
    static int K;
    static int[] dp1, dp2;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        K = Integer.parseInt(br.readLine());
        dp1 = new int[K+1];
        dp2 = new int[K+1];

        dp1[0] = 1;
        dp2[0] = 0;

        for (int i = 1; i <= K; i++) {
            dp1[i] = dp2[i-1];
            dp2[i] = dp1[i-1] + dp2[i-1];
        }

        StringBuilder sb = new StringBuilder();
        sb.append(dp1[K]).append(" ").append(dp2[K]);
        System.out.println(sb);
    }
}