import java.util.*;
import java.io.*;

public class Main {

    static int N; // 동굴의 길이 2 <= N <= 200,000
    static int H; // 동굴의 높이 2 <= H <= 500,000
    static List<Integer> low = new ArrayList<>();
    static List<Integer> high = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        H = stoi(st.nextToken());

        for (int i = 1; i <= N; i++) {
            if (i % 2 == 0) {
                high.add(stoi(br.readLine()));
            } else {
                low.add(stoi(br.readLine()));
            }
        }

        Collections.sort(high);
        Collections.sort(low);
        int ans = Integer.MAX_VALUE;
        int ansCnt = 0;
        for (int i = 1; i <= H; i++) {
            int cnt = lowerBound(i, low);
            cnt += lowerBound(H - i + 1 , high);

            cnt = N - cnt;

            if (ans == cnt) {
                ansCnt++;
            } else if(ans > cnt) {
                ans = cnt;
                ansCnt = 1;
            }
        }

        System.out.print(ans + " " + ansCnt);
    }

    static int lowerBound(int target, List<Integer> list) {
        int l = 0, r = list.size();

        while (l < r) {
            int mid = (l + r) / 2;
            if (list.get(mid) >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }

}
