import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = stoi(br.readLine());
        while (t-- > 0) {
            int n = stoi(br.readLine());
            Queue<String> alpha = new ArrayDeque<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                alpha.offer(st.nextToken());
            }
            Deque<String> str = new ArrayDeque<>();
            str.add(alpha.poll());
            while (!alpha.isEmpty()) {
                String s = alpha.poll();
                if (str.getFirst().compareTo(s) >= 0) {
                    str.addFirst(s);
                } else {
                    str.addLast(s);
                }
            }

            StringBuilder sb = new StringBuilder();
            str.forEach(sb::append);
            System.out.println(sb);
        }
    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }
}

