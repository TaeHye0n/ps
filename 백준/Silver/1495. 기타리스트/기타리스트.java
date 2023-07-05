import java.io.*;
import java.util.*;

public class Main {
    static int N, S, M; //곡의개수, 시작볼륨, 맥스볼륨
    static int[] volume;
    static boolean[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        volume = new int[N+1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            volume[i] = Integer.parseInt(st.nextToken());
        }
        dp = new boolean[N+1][M+1];
        if (S + volume[1] <= M) dp[1][S+volume[1]] = true;
        if (S - volume[1] >= 0) dp[1][S-volume[1]] = true;

        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if (dp[i-1][j]) {
                    if (j + volume[i] <= M) dp[i][j+volume[i]] = true;
                    if (j - volume[i] >= 0) dp[i][j-volume[i]] = true;
                }
            }
        }

        for (int i = M; i >= 0; i--) {
            if (dp[N][i]) {
                System.out.println(i);
                return;
            }
        }

        System.out.println(-1);
    }
}
