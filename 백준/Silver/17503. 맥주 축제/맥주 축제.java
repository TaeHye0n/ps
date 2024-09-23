import java.util.*;
import java.io.*;

public class Main {

    static int N; // 축제가 열리는 기간 1 <= N <= 200,000
    static int M; // 채워야 하는 선호도의 합 1 <= M < 2^31
    static int K; // 마실수 있는 맥주 종료의 수 N <= K <= 200,000

    static class Beer implements Comparable<Beer> {
        int deg;
        int favor;

        public Beer(int deg, int favor) {
            this.deg = deg;
            this.favor = favor;
        }

        @Override
        public int compareTo(Beer o) {
            if (this.deg == o.deg) return o.favor - this.favor;
            return this.deg - o.deg;
        }

    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());
        K = stoi(st.nextToken());

        long ans = Long.MAX_VALUE;
        List<Beer> list = new ArrayList<>();

        long l = 0, r = 0;
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int favor = stoi(st.nextToken());
            int deg = stoi(st.nextToken());
            r = Math.max(deg, r);
            list.add(new Beer(deg, favor));
        }

        Collections.sort(list);

        while (l <= r) {
            long mid = (l + r) / 2;
            List<Integer> candidates = new ArrayList<>();
            for (int i = 0; i < K; i++) {
                Beer cur = list.get(i);
                if (cur.deg <= mid) {
                    candidates.add(cur.favor);
                }
            }

            if (candidates.size() >= N) {
                Collections.sort(candidates, Collections.reverseOrder());
                long sum = 0;
                for (int i = 0; i < N; i++) {
                    sum += candidates.get(i);
                }

                if (sum >= M) {
                    ans = Math.min(ans, mid);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                l = mid + 1;
            }
        }

        if (ans == Long.MAX_VALUE)
            System.out.println(-1);
        else {
            System.out.println(ans);
        }

    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }
}
