import java.util.*;
import java.io.*;

public class Main {
    static class Stuff{
        int value;
        int weight;

        Stuff(int value, int weight){
            this.value = value;
            this.weight = weight;
        }
    }
    static int n, k;
    static Stuff[] stuffs;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        stuffs = new Stuff[n+1];
        dp = new int[n+1][k+1];
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            int weight = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());
            stuffs[i] = new Stuff(value,weight);
        }

        for(int i = 1; i<= n; i++){
            for(int j = 1; j <= k; j++){
                if(j - stuffs[i].weight >= 0){
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-stuffs[i].weight] + stuffs[i].value);
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        System.out.println(dp[n][k]);
    }
}