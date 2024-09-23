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
            if (this.deg == o.deg) {
                return o.favor - this.favor;
            }
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

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int favor = stoi(st.nextToken());
            int deg = stoi(st.nextToken());
            list.add(new Beer(deg, favor));
        }

        Collections.sort(list);

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        long sum = 0L;
        for (int i = 0; i < K; i++) {
            pq.offer(list.get(i).favor);
            sum += list.get(i).favor;

            if (pq.size() > N) {
                sum -= pq.poll();
            }

            if (pq.size() == N && sum >= M) {
                ans = list.get(i).deg;
                break;
            }
        }

        if (ans == Long.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }
}
