import java.util.*;
import java.io.*;

public class Main{
    static int T;
    static int[][] dp;
    static final int MAX = 31;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        T = Integer.parseInt(br.readLine());
        dp = new int[MAX][MAX];
        StringBuilder sb = new StringBuilder();
        while(T-- > 0){
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            sb.append(comb(e,w) + "\n");
        }
        System.out.println(sb.toString());
    }
    private static int comb(int n, int r){
        if(dp[n][r] > 0){
            return dp[n][r];
        }

        if(n == r || r == 0 ) return dp[n][r] = 1;

        return dp[n][r] = comb(n-1, r-1) + comb(n-1, r);
    }

}