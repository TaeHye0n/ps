import java.io.*;
import java.util.*;

public class Main {

  static int N; // 학생들의 수 2 <= N <= 500
  static int M; // 학생 키를 비교한 횟수 0 <= M <= N(N-1) / 2
  static int ans;
  static final int INF = 987654321;

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = stoi(st.nextToken());
    M = stoi(st.nextToken());
    ans = 0;

    int[][] adj = new int[N + 1][N + 1];

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j) {
          continue;
        }
        adj[i][j] = INF;
      }
    }

    for (int i = 1; i <= M; i++) {
      st = new StringTokenizer(br.readLine());
      int from = stoi(st.nextToken());
      int to = stoi(st.nextToken());
      adj[from][to] = 1;
    }

    for (int k = 1; k <= N; k++) {
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
          adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
        }
      }
    }

    for (int i = 1; i <= N; i++) {
      int cnt = 0;
      for (int j = 1; j <= N; j++) {
        if (i == j) {
          continue;
        }
        if (adj[i][j] != INF || adj[j][i] != INF) {
          cnt++;
        }
      }

      if (cnt == N - 1) {
        ans++;
      }
    }
    System.out.println(ans);

  }

  static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

