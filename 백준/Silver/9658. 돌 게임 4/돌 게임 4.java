import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = stoi(br.readLine()); // 1 <= N <= 1,000 돌 의 개수
    int[] dp = new int[1001]; // 0은 창영 win, 1은 상근 win

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;

    for (int i = 5; i <= N; i++) {
      if (dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1) {
        dp[i] = 0;
      } else {
        dp[i] = 1;
      }
    }

    if (dp[N] == 0) {
      System.out.println("CY");
    } else {
      System.out.println("SK");
    }
  }

  static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

