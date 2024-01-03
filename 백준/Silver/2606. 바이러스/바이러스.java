import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

// 1. 바이러스 https://www.acmicpc.net/problem/2606
public class Main {
  static int N; //컴퓨터의 개수
  static int M; //컴퓨터 쌍의 수
  static List<Integer>[] network; //네트워크 그래프
  static int answer;
  public static void main(String[] args) throws IOException {
    answer = 0;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    M = Integer.parseInt(br.readLine());
    network = new List[N + 1];

    for (int i = 0; i <= N; i++) {
      network[i] = new ArrayList<>();
    }

    for (int i = 0; i < M; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());
      network[s].add(e);
      network[e].add(s);
    }

    bfs();
    System.out.println(answer);
  }

  private static void bfs() {
    boolean[] visited = new boolean[N + 1];
    visited[1] = true;
    Queue<Integer> q = new LinkedList<>();
    q.offer(1);

    while (!q.isEmpty()) {
      int cur = q.poll();

      for (int i = 0; i < network[cur].size(); i++) {
        int next = network[cur].get(i);
        if (!visited[next]) {
          visited[next] = true;
          q.offer(next);
          answer++;
        }
      }
    }
  }
}
