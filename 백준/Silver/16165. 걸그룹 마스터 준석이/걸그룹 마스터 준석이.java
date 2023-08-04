import java.io.*;
import java.util.*;

public class Main {
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        Map<String, String> memToGroup = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String group = br.readLine();
            int cnt = Integer.parseInt(br.readLine());
            for (int j = 0; j < cnt; j++) {
                String mem = br.readLine();
                memToGroup.put(mem, group);
            }
        }

        for (int i = 0; i < M; i++) {
            String str = br.readLine();
            int query = Integer.parseInt(br.readLine());
            if (query == 0) {
                memToGroup.keySet().stream().filter(s -> memToGroup.get(s).equals(str))
                        .sorted((s1, s2) -> s1.compareTo(s2))
                        .forEach(k -> sb.append(k + "\n"));
            } else {
                sb.append(memToGroup.get(str) + "\n");
            }
        }
        System.out.println(sb);
    }
}