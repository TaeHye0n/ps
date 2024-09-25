import java.io.*;
import java.util.*;

public class Main {

  static long[][] dp = new long[31][31]; // w, h 개로 만드는 문자열 경우의 수

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int cnt = 0;
    while (true) {
      int n = stoi(br.readLine());
      if (n == 0) {
        break;
      }

      if (cnt == 0) {
        cnt++;
        for (int w = 1; w <= 30; w++) {
          for (int h = 0; h <= w; h++) {
            if (h == 0) {
              dp[w][h] = 1L;
            } else {
              dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
            }
          }
        }
      }
      System.out.println(dp[n][n]);

    }
  }

  static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

