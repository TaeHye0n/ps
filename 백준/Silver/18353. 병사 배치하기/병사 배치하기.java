import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] soldiers = new int[N+1];
        int[] dp = new int[N+1];
        int answer = 0;

        for (int i = 1; i <= N; i++) {
            soldiers[i] = Integer.parseInt(st.nextToken());
            dp[i] = 1;
            for (int j = 1; j < i; j++) {
                if(soldiers[i] < soldiers[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            answer = Math.max(answer, dp[i]);
        }
        System.out.println(N - answer);
    }
}