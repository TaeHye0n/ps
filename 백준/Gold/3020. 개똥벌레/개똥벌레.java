import java.util.*;
import java.io.*;

public class Main {

    static int N; // 동굴의 길이 2 <= N <= 200,000
    static int H; // 동굴의 높이 2 <= H <= 500,000

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        H = stoi(st.nextToken());
        int[] low = new int[H + 1];
        int[] high = new int[H + 1];
        for (int i = 1; i <= N; i++) {
            int a = stoi(br.readLine());
            if (i % 2 == 0) {
                high[H- a + 1]++;
            } else {
                low[a]++;
            }
        }

        for (int i = 1; i < H; i++) {
            high[i + 1] += high[i];
        }

        for (int i = H - 1; i > 1; i--) {
            low[i - 1] += low[i];
        }

        int[] sum = new int[H + 1];
        for (int i = 1; i <= H; i++) {
            sum[i] = low[i] + high[i];
        }

        Arrays.sort(sum);

        int cnt = 1;
        int val = sum[1];
        for (int i = 2; i <= H; i++) {
            if (sum[i] == val) {
                cnt++;
            } else break;
        }

        System.out.println(val + " " + cnt);

    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }

}
