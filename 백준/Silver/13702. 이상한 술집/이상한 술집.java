import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static long[] volume;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        volume = new long[N + 1];
        long max = 0;
        for (int i = 1; i <= N; i++) {
            volume[i] = Long.parseLong(br.readLine());
            max = Math.max(volume[i], max);
        }

        long l = 1;
        long r = max;
        long answer = 0L;

        while (l <= r) {
            long mid = (l + r) / 2;
            if (K <= calCount(mid)) {
                answer = Math.max(mid, answer);
                l = mid + 1;
            } else r = mid - 1;
        }
        System.out.println(answer);
    }

    private static int calCount(long mid) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            count += volume[i] / mid;
        }
        return count;
    }
}