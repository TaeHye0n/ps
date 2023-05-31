import java.util.*;
import java.io.*;

public class Main {
    static int[] parent;
    static int N;
    static long answer;
    static ArrayList<Edge> graph = new ArrayList<>();
    static class Edge implements Comparable<Edge>{
        int from, to, cost;

        public Edge(int from, int to, int cost){
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o){
            return this.cost - o.cost;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = null;
        parent = new int[N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                int cost = Integer.parseInt(st.nextToken());
                graph.add(new Edge(i,j,cost));
            }
            parent[i] = i;
        }

        Collections.sort(graph);
        int cnt = 0;
        for(Edge edge: graph) {
            if(find(edge.from) != find(edge.to)){
                answer += edge.cost;
                Union(edge.from, edge.to);
                if(cnt == N-1) break;
            }
        }
        System.out.println(answer);
    }
    private static int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    private static void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        parent[y] = x;
    }
}