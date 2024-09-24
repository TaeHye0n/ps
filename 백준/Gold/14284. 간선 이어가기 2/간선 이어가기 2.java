import java.util.*;
import java.io.*;

public class Main {

    static final int INF = 987654321;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = stoi(st.nextToken()); // 정점의 개수 2 <= n <= 5000
        int m = stoi(st.nextToken()); // 간선의 개수 1 <= m <= 100000

        List<Edge>[] adj = new List[n + 1];
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);

        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = stoi(st.nextToken());
            int b = stoi(st.nextToken());
            int c = stoi(st.nextToken());

            adj[a].add(new Edge(c, b));
            adj[b].add(new Edge(c, a));
        }

        st = new StringTokenizer(br.readLine());
        int s = stoi(st.nextToken());
        int t = stoi(st.nextToken());

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        dist[s] = 0;
        pq.offer(new Edge(0, s));

        while (!pq.isEmpty()) {
            Edge cur = pq.poll();

            if (dist[cur.node] != cur.cost) continue;

            for (Edge nxt : adj[cur.node]) {
                if (dist[nxt.node] > dist[cur.node] + nxt.cost) {
                    dist[nxt.node] = dist[cur.node] + nxt.cost;
                    pq.offer(new Edge(dist[nxt.node], nxt.node));
                }
            }
        }

        System.out.println(dist[t]);

    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }


    static class Edge implements Comparable<Edge> {
        int cost;
        int node;

        public Edge(int cost, int node) {
            this.cost = cost;
            this.node = node;
        }

        @Override
        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }
}
