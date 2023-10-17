import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] use;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        use = new int[N + 1];
        int max = 0;
        for (int i = 1; i <= N; i++) {
            use[i] = Integer.parseInt(br.readLine());
            max = Math.max(max, use[i]);
        }

        int l = max;
        int r = 10000 * 100000;
        int answer = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (calCount(mid) == 0) {
                l = mid + 1;
                continue;
            }
            if (M >= calCount(mid)) {
                answer = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        System.out.println(answer);
    }

    static int calCount(int mid) {
        int count = 1;
        int money = mid;
        for (int i = 1; i <= N; i++) {
            if (mid < use[i]) return 0;
            money -= use[i];
            if (money < 0) {
                count++;
                money = mid - use[i];
            }
        }
        return count;
    }
}