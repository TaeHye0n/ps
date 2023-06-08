import java.util.*;
import java.io.*;

public class Main{
    static int C, N;
    static final int INF = 987654321;
    static int[][] cost;
    static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        C = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        cost = new int[N+1][2];
        dp = new int[C+101];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(br.readLine());
            cost[i][0] = Integer.parseInt(st.nextToken());
            cost[i][1] = Integer.parseInt(st.nextToken());
            for(int j = cost[i][1]; j < C + 101; j++){
                dp[j] = Math.min(dp[j], (cost[i][0] + dp[j - cost[i][1]]));
            }
        }
        int ans = INF;
        for(int i = C; i <= C+100; i++){
            ans = Math.min(ans, dp[i]);
        }
        System.out.println(ans);
    }
}