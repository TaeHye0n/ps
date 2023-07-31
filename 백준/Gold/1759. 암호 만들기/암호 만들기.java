import java.io.*;
import java.util.*;

public class Main {
    static int L, C;
    static Character[] alpha;
    static StringBuilder sb = new StringBuilder();
    static List<Character> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        alpha = new Character[C];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < C; i++) {
            alpha[i] = st.nextToken().charAt(0);
        }
        Arrays.sort(alpha);
        func(0, 0);
        System.out.println(sb);
    }

    private static void func(int cnt, int idx) {
        if (cnt == L) {
            boolean flag = false;
            int cnt1 = 0, cnt2 = 0;
            for (Character c : list) {
                if (isAeiou(c)) cnt1++;
                else cnt2++;
            }

            if (cnt1 >= 1 && cnt2 >= 2) flag = true;

            if (flag) {
                list.forEach(c -> sb.append(c));
                sb.append("\n");
            }
            return;
        }

        for (int i = idx; i < C; i++) {
            list.add(alpha[i]);
            func(cnt + 1, i + 1);
            list.remove(list.size()-1);
        }
    }

    private static boolean isAeiou(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}