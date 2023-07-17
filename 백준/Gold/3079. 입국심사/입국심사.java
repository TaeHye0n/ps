import java.io.*;
import java.util.*;

public class Main {
    /**
     * N = 임국심사대의 수
     * M = 사람 수
     */
    static int N, M;
    static long[] T;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = new long[N + 1];

        for (int i = 1; i <= N; i++) {
            T[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(T);

        long left = 0;
        long right = (long) T[N]*M;
        while (left <= right) {
            long mid = (left + right) / 2;
            long cnt = 0;
            for (int i = 1; i <= N; i++) {
                cnt += mid / T[i];
                if (cnt >= M) break;
            }

            if (cnt < M) left = mid + 1;
            else right = mid - 1;
        }
        System.out.println(left);
    }
}