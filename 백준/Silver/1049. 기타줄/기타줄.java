import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<Integer> pack = new ArrayList<>();
        List<Integer> each = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            pack.add(Integer.parseInt(st.nextToken()));
            each.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(pack);
        Collections.sort(each);

        int val1 = (N / 6 + 1) * pack.get(0);
        int val2 = N * each.get(0);
        int val3 = (N / 6) * pack.get(0) + (N % 6) * each.get(0);

        int min = Math.min(val1, Math.min(val2, val3));

        System.out.println(min);
    }
}