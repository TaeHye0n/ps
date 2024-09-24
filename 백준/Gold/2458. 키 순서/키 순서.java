import java.io.*;
import java.util.*;

public class Main {

  static int N; // 학생들의 수 2 <= N <= 500
  static int M; // 학생 키를 비교한 횟수 0 <= M <= N(N-1) / 2
  static int ans;
  static boolean[] visited;
  static int cnt;

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = stoi(st.nextToken());
    M = stoi(st.nextToken());
    ans = 0;
    List<Integer>[] graph = new List[N + 1];
    List<Integer>[] reverseGraph = new List[N + 1];
    visited = new boolean[N + 1];
    for (int i = 0; i <= N; i++) {
      graph[i] = new ArrayList<>();
      reverseGraph[i] = new ArrayList<>();
    }

    for (int i = 1; i <= M; i++) {
      st = new StringTokenizer(br.readLine());
      int from = stoi(st.nextToken());
      int to = stoi(st.nextToken());
      graph[from].add(to);
      reverseGraph[to].add(from);
    }

    for (int i = 1; i <= N; i++) {
      cnt = 0;
      Arrays.fill(visited, false);
      dfs(i, graph);
      Arrays.fill(visited, false);
      dfs(i, reverseGraph);
      if (cnt == N - 1) {
        ans++;
      }
    }

    System.out.println(ans);

  }

  static void dfs(int idx, List<Integer>[] list) {
    for (int i = 0; i < list[idx].size(); i++) {
      int next = list[idx].get(i);
      if (visited[next]) {
        continue;
      }
      visited[next] = true;
      cnt++;
      dfs(next, list);
    }
  }

  static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

