import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] score;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        score = new int[N + 1];
        dp = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            score[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N; i++) {
            int max = -1;
            int min = 10001;
            for (int j = i; j > 0; j--) {
                max = Math.max(max, score[j]);
                min = Math.min(min, score[j]);
                dp[i] = Math.max(dp[i], max - min + dp[j-1]);
            }
        }
        System.out.println(dp[N]);
    }
}