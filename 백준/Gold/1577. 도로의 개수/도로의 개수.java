import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = stoi(st.nextToken()); // 가로 크기 N <= 100
        int M = stoi(st.nextToken()); // 세로 크기 M <= 100
        int K = stoi(br.readLine()); // 공사중인 도로의 개수 0 <= K <= 50

        int[][][] road = new int[M + 1][N + 1][2];// 0 : 위 , 1 : 오른
        long[][] dp = new long[M + 1][N + 1];

        dp[0][0] = 1L;

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = stoi(st.nextToken());
            int b = stoi(st.nextToken());
            int c = stoi(st.nextToken());
            int d = stoi(st.nextToken());
            int maxX = Math.max(a, c);
            int minX = Math.min(a, c);
            int maxY = Math.max(b, d);
            int minY = Math.min(b, d);

            if (maxX - minX == 1) {
                road[maxY][maxX][1] = -1;
            } else if (maxY - minY == 1) {
                road[maxY][maxX][0] = -1;
            }
        }

        for (int i = 0; i <= N; i++) {
            if (road[0][i][1] == -1) {
                break;
            }
            dp[0][i] = 1L;
        }

        for (int i = 0; i <= M; i++) {
            if (road[i][0][0] == -1) {
                break;
            }
            dp[i][0] = 1L;
        }

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (road[i][j][0] == -1 && road[i][j][1] == -1) {
                    dp[i][j] = 0L;
                } else if (road[i][j][0] == -1) {
                    dp[i][j] = dp[i][j - 1];
                } else if (road[i][j][1] == -1) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        System.out.println(dp[M][N]);

    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }

}
