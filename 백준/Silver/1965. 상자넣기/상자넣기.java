import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int[] arr;
    static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[n+1];
        dp = new int[n+1];
        int max = 0;

        for(int i = 1; i <= n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 1; i <= n; i++){
            dp[i] = 1;
            for(int j = 1; j < i; j++){
                if(arr[i] > arr[j]) dp[i] = Math.max(dp[i],dp[j]+1);
            }
            max = Math.max(max,dp[i]);
        }
        System.out.println(max);
    }
}