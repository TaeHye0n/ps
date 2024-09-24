import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = stoi(st.nextToken()); // 길이가 N인 수열 1 <= N <= 200,000
        int K = stoi(st.nextToken()); // 같은 원소 제한 K개 1 <= K <= 100

        st = new StringTokenizer(br.readLine());
        List<Integer> list = new ArrayList<>();
        int[] cnt = new int[100_001];

        list.add(0);
        while (st.hasMoreTokens()) {
            list.add(stoi(st.nextToken()));
        }

        int ans = 1;

        int l = 1, r = 2;
        cnt[list.get(1)]++;
        while (r <= N) {
            cnt[list.get(r)]++;

            while (cnt[list.get(r)] > K) {
                cnt[list.get(l)]--;
                l++;
            }

            ans = Math.max(ans, r - l + 1);

            r++;
        }
        System.out.println(ans);
    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }


}
