import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        Queue<Integer> q = new LinkedList<>();

        while (true) {
            int query = Integer.parseInt(br.readLine());
            if (query == 0) q.remove();
            else if (query == -1) break;
            else {
                if (q.size() == N) continue;
                q.offer(query);
            }
        }
        if (q.isEmpty()) sb.append("empty");
        while (!q.isEmpty()) {
            sb.append(q.poll()).append("\n");
        }
        System.out.println(sb);
    }
}