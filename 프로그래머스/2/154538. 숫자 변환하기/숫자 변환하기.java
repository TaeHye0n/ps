import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static final int MAX_NUMBER = 1_000_000;
    static int[] dp;

    public int solution(int x, int y, int n) {

        dp = new int[MAX_NUMBER + 1];

        Queue<Integer> q = new LinkedList<>();
        q.offer(x);

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : new int[]{cur + n, cur * 2, cur * 3}) {
                if (next > y) continue;
                if (dp[next]  != 0) continue;
                dp[next] = dp[cur] + 1;
                q.offer(next);
            }
        }
        if (dp[y] == 0 && y != x) return -1;
        return dp[y];
    }
}