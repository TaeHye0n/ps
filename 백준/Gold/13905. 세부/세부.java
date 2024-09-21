import java.util.*;
import java.io.*;

public class Main {
    static int N = 0, M = 0; // 집의 수 N, 다리의 수 M
    static int S = 0, E = 0; // 시작 점 S, 끝 점 E
    static Tuple[] edges; // 간선 리스트
    static int[] p; // 음수는 rank, 양수는 root
    public static void main(String[] args) throws Exception {
        long answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        edges = new Tuple[M];
        p = new int[N + 1];
        Arrays.fill(p, -1);

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            edges[i] = new Tuple(cost, start, end);
        }

        Arrays.sort(edges);

        // 최대 스패닝 트리 생성
        for (int i = 0; i < M; i++) {
            Tuple edge = edges[i];
            if (!isDiffGroup(edge.st, edge.ed)) continue;
            // 유니온 파인드를 활용한 최대 스패닝 트리 - 크루스칼 알고리즘은 간선의 무게제한이 큰 것부터 연결한다
            // 그래서 시작 점과 끝 점의 Root가 같아지는 순간이 S부터 E까지 가는 간선들 중 최소 무게제한이다.
            if (find(S) == find(E)) {
                answer = edge.cost;
                break;
            }
        }
        System.out.println(answer);
    }

    // root 찾기
    static int find(int x) {
        if (p[x] < 0) return x;
        return p[x] = find(p[x]); // 경로 압축
    }

    static boolean isDiffGroup(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        // Union By Rank
        if (p[u] == p[v]) p[u]--;
        if (p[u] < p[v]) p[v] = u;
        else p[u] = v;
        return true;
    }

    static class Tuple implements Comparable<Tuple> {
        int cost;
        int st;
        int ed;

        public Tuple (int cost, int st, int ed) {
            this.cost = cost;
            this.st = st;
            this.ed = ed;
        }

        // cost 기준 내림차순
        @Override
        public int compareTo(Tuple o) {
            return -1 * (this.cost - o.cost);
        }
    }
}
