import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static class Task {
        int t;
        int p;

        public Task(int t, int p) {
            this.t = t;
            this.p = p;
        }
    }
    static List<Task> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        list.add(null);
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            list.add(new Task(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        list.add(new Task(0,0));

        int[] dp = new int[N+2];

        int max = 0;
        for (int i = 1; i <= N+1; i++) {
            max = Math.max(max, dp[i]);
            int next = i + list.get(i).t;
            if(next > N + 1) continue;
            dp[next] = Math.max(dp[next], max + list.get(i).p);
        }
        System.out.println(dp[N+1]);
    }
}