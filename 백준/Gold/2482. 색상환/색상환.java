import java.util.*;
import java.io.*;

public class Main {

    static int N; // 색상환에 포함된 색의 개수 4 <= N <= 1,000
    static int K; // 선택할 색의 개수 1 <= K <= N
    static final Integer MOD = 1000000003;

    // 색상환에서 서로 이웃하지 않는 색들을 선택해야 한다.
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = stoi(br.readLine());
        K = stoi(br.readLine());

        int[][] dp = new int[N + 1][N + 1]; // dp[i][j] -> i개의 색을가진 선형 색 리스트에서 j개의 색을 선택하는 경우의 수

        for (int i = 1; i <= N; i++) {
            dp[i][0] = 1; // 점화식을 위해서 1로 초기화
            dp[i][1] = i;
        }

        /**
         * j 가 {(i + 1) / 2} + 1 이상 인 경우는 0
         * dp[1][0] = 0, dp[1][1] = 1
         * dp[2][0] = 0, dp[2][1] = 2
         * dp[3][0] = 0, dp[3][1] = 3, dp[3][2] = 1
         * dp[4][0] = 0, dp[4][1] = 4, dp[4][2] = 2
         *
         * dp[i][j] = dp[i-1][j] + dp[i-2][j-1];
         * i번째에 새로 추가된 색을 안뽑는 경우 + 뽑는 경우
         */
        for (int i = 3; i <= N; i++) {
            for (int j = 2; j <= (i + 1) / 2; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
            }
        }

        // 색상환은 원형이기 때문에 N번째 것을 뽑으려면 첫 번째 색을 뽑으면 안된다.
        int ans = (dp[N - 1][K] + dp[N - 3][K - 1]) % MOD;
        System.out.println(ans);
    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }
}
