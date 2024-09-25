import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int t = stoi(br.readLine());

    while (t-- > 0) {
      int k = stoi(br.readLine()); // 소설을 구성하는 장의 수 3 <= k <= 1,000,000
      StringTokenizer st = new StringTokenizer(br.readLine());
      PriorityQueue<Long> pq = new PriorityQueue<>();
      for (int i = 1; i <= k; i++) {
        pq.offer(Long.parseLong(st.nextToken()));
      }
      long ans = 0L;

      while (pq.size() > 1) {
        long a = pq.poll();
        long b = pq.poll();
        ans += (a + b);
        pq.offer(a + b);
      }
      System.out.println(ans);
    }
  }

  static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

