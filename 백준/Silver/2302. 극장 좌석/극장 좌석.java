import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        dp = new int[N+1];

        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= N; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        int answer = 1;

        int before = 0;
        for(int i = 0; i < M; i++){
            int vip = Integer.parseInt(br.readLine());
            answer *= dp[vip - before - 1];
            before = vip;
        }
        answer *= dp[N - before];
        System.out.println(answer);
    }
}