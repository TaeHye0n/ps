import java.util.*;
import java.io.*;

public class Main {

    static int n; // 횡단보도 개수 1 <= n <= 100000
    static int k; // 연속한 신호등의 개수 == target
    static int b; // 망가진 신호등의 개수

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = stoi(st.nextToken());
        k = stoi(st.nextToken());
        b = stoi(st.nextToken());

        int[] arr = new int[n + 1];
        Arrays.fill(arr, 1);

        for (int i = 0; i < b; i++) {
            int idx = stoi(br.readLine());
            arr[idx - 1]--;
        }
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += arr[i];
        }
        int ans = b;

        for (int i = 1; i <= n - k; i++) {
            cnt -= arr[i - 1];
            cnt += arr[i + k - 1];
            int broken = k - cnt;
            ans = Math.min(ans, broken);
        }
        System.out.println(ans);
    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }
}
