import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = stoi(br.readLine()); // 악보의 개수 1 <= N <= 100,000

    StringTokenizer st = new StringTokenizer(br.readLine());
    int[] score = new int[N + 2];

    for (int i = 1; i <= N; i++) {
      score[i] = stoi(st.nextToken());
    }

    int Q = stoi(br.readLine());

    int[] sum = new int[N + 2];

    for (int i = 1; i < N; i++) {
      if (score[i + 1] < score[i]) {
        sum[i] = sum[i - 1] + 1;
      } else {
        sum[i] = sum[i - 1];
      }
    }

    for (int i = 0; i < Q; i++) {
      st = new StringTokenizer(br.readLine());
      int s = stoi(st.nextToken());
      int e = stoi(st.nextToken());
      System.out.println(sum[e - 1] - sum[s - 1]);
    }

  }

  static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

