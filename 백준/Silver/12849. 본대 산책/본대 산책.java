import java.io.*;
import java.util.*;

public class Main {
    /**
     * 0 정보과학관
     * 1 전산관
     * 2 신양관
     * 3 진리관
     * 4 학생회관
     * 5 형남공학관
     * 6 환경직기념관
     * 7 미래관
     */
    static final long div = 1_000_000_007;
    static int D;
    static long[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        D = Integer.parseInt(br.readLine());
        dp = new long[D+1][8];
        dp[0][0] = 1;

        for (int i = 1; i <= D; i++) {
            dp[i][0] = (dp[i-1][1] + dp[i-1][7]) % div;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][7]) % div;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][6] + dp[i-1][7]) % div;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4] + dp[i-1][6]) % div;
            dp[i][4] = (dp[i-1][3] + dp[i-1][5]) % div;
            dp[i][5] = (dp[i-1][4] + dp[i-1][6]) % div;
            dp[i][6] = (dp[i-1][2] + dp[i-1][3] + dp[i-1][5] + dp[i-1][7]) % div;
            dp[i][7] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][6]) % div;
        }

        System.out.println(dp[D][0]);
    }

}