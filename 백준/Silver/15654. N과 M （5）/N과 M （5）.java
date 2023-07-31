import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] nums;
    static boolean[] used;
    static StringBuilder sb = new StringBuilder();
    static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        nums = new int[N];
        used = new boolean[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(nums);
        func(0);
        System.out.println(sb);
    }

    private static void func(int cnt) {
        if(cnt == M) {
            list.forEach(o -> sb.append(o).append(" "));
            sb.append("\n");
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                list.add(nums[i]);
                used[i] = true;
                func(cnt + 1);
                list.remove(list.size() - 1);
                used[i] = false;
            }
        }
    }
}
