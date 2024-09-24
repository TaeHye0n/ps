import java.io.*;
import java.util.*;

public class Main {

  static int N; // 연병장의 크기 1 <= N <= 100,000
  static int M; // 조교의 수 1 <= M <= 100,000

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = stoi(st.nextToken());
    M = stoi(st.nextToken());
    int[] arr = new int[N + 2];
    int[] amount = new int[N + 2];

    st = new StringTokenizer(br.readLine());
    for (int i = 1; i <= N; i++) {
      arr[i] = stoi(st.nextToken());
    }

    for (int i = 1; i <= M; i++) {
      st = new StringTokenizer(br.readLine());
      int s = stoi(st.nextToken());
      int e = stoi(st.nextToken());
      int deg = stoi(st.nextToken());
      amount[s] += deg;
      amount[e + 1] -= deg;
    }

    for (int i = 1; i < N; i++) {
      amount[i + 1] += amount[i];
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= N; i++) {
      arr[i] += amount[i];
      sb.append(arr[i]).append(" ");
    }
    System.out.println(sb);

  }

  static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

