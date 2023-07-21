import java.io.*;
import java.util.*;

public class Solution {
    /**
     * 첫 번째 날 열쇠는 A가 가지고 있음
     * 열쇠를 가진 사람과 담당자는 무조건 활동에 참여
     * 모든 활동이 끝난 후 열쇠는 누가 가지든 상관 없음
     *
     */
    static final int mod = 1_000_000_007;
    static int T; //테스트 케이스
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int t = 1; t <= T; t++) {
            String managers = br.readLine();
            dp = new int[managers.length()][16];
            int answer = solve(managers);
            sb.append("#").append(t).append(" ").append(answer).append("\n");
        }
        System.out.println(sb);
    }

    private static int solve(String managers) {
        int ans = 0;
        for (int i = 0; i < managers.length(); i++) {
            int manager = 1 << (managers.charAt(i) - 'A');

            for (int j = 1; j < 16; j++) {
                if (i == 0) {
                    if ((j & manager) != 0  && (j & 1) != 0) { // 담당자를 포함하고 첫날엔 A가 무조건 있어야함
                        dp[i][j] = 1;
                    }
                } else {
                    if (dp[i-1][j] == 0) continue;
                    for (int k = 1; k < 16; k++) {
                        if ((j & k) != 0 && (k & manager) != 0) { //어제 나온 사람이 오늘 나오고(열쇠), 오늘 나온사람이 담당자
                            dp[i][k] = (dp[i][k] + dp[i-1][j]) % mod;
                        }
                    }
                }
            }
        }
        for (int i = 1; i < 16; i++) {
            ans = (ans + dp[managers.length()-1][i]) % mod;
        }
        return ans;
    }
}