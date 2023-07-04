import java.io.*;
import java.util.*;

public class Main {
    static int N; //과목의 수
    static int M; //선수 조건의 수
    static int[] deg;
    static int[] answer;
    static List<List<Integer>> graph = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        deg = new int[N+1];
        answer = new int[N+1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            graph.get(from).add(to);
            deg[to]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (deg[i] == 0) {
                answer[i] = 1;
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : graph.get(cur)) {
                if (--deg[next] == 0) {
                    q.offer(next);
                    answer[next] = answer[cur] + 1;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            sb.append(answer[i]).append(" ");
        }
        System.out.println(sb);
    }
}
