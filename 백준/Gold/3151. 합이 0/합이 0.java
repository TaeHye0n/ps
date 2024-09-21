import java.util.*;
import java.io.*;

public class Main {
  static int N = 0;

  public static void main(String[] args) throws Exception {
    long answer = 0;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    int[] arr = new int[N];
    StringTokenizer st = new StringTokenizer(br.readLine());
    int idx = 0;
    while (st.hasMoreTokens()) {
      arr[idx++] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(arr);

    for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j < N; j++) {
        int target = -1 * (arr[i] + arr[j]);
        int lower_idx = lower_bound(j + 1, N, target, arr);
        int upper_idx = upper_bound(j + 1, N, target, arr);
        answer += (upper_idx - lower_idx);
      }
    }

    System.out.println(answer);
  }

  static int lower_bound(int l, int r, int target, int[] arr) {
    while (l < r) {
      int mid = (l + r) / 2;
      if (arr[mid] >= target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }

  static int upper_bound(int l, int r, int target, int[] arr) {
    while (l < r) {
      int mid = (l + r) / 2;
      if (arr[mid] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
}
