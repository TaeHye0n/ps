import java.util.*;
import java.io.*;

public class Main {
    static int N; //우주신들의 개수
    static int M; //연결된 통로의 개수
    static int[] parent;
    static class Edge implements Comparable<Edge>{
        int start;
        int end;
        double weight;

        public Edge(int start, int end, double weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o){
            return Double.compare(this.weight, o.weight);
        }
    }
    static double answer;
    static List<Edge> edges = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        parent = new int[N+1];
        for(int i = 1; i <= N; i++){
            parent[i] = i;
        }
        int[][] pos = new int[N+1][2];

        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(br.readLine());
            pos[i][0] = Integer.parseInt(st.nextToken());
            pos[i][1] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            union(start, end);
        }

        for(int i = 1; i < N; i++){
            for(int j = i + 1; j <= N; j++){
                int x1 = pos[i][0];
                int y1 = pos[i][1];
                int x2 = pos[j][0];
                int y2 = pos[j][1];

                double weight = Math.sqrt(Math.pow(x1-x2,2) + Math.pow(y1-y2,2));

                edges.add(new Edge(i, j, weight));
            }
        }

        Collections.sort(edges);

        answer = 0;
        for(Edge edge : edges){
            if(find(edge.start) != find(edge.end)){
                answer += edge.weight;
                union(edge.start, edge.end);
            }
        }
        System.out.println(String.format("%.2f", answer));
    }
    private static int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    private static void union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        parent[x] = y;
    }
}