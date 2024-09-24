import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = stoi(br.readLine());

    StringBuilder sb = new StringBuilder();
    PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
    for (int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int a = stoi(st.nextToken());
      if (a == 0) {
        if (pq.isEmpty()) {
          sb.append("-1\n");
          continue;
        }
        sb.append(pq.poll()).append("\n");
      } else {
        while (st.hasMoreTokens()) {
          pq.offer(stoi(st.nextToken()));
        }
      }
    }
    System.out.println(sb);
  }

  static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

