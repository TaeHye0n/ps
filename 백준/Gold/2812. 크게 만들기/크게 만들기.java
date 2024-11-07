import java.util.*;
import java.io.*;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = 0, k = 0;
    StringTokenizer st = new StringTokenizer(br.readLine());
    n = stoi(st.nextToken());
    k = stoi(st.nextToken());

    String num = br.readLine();
    char[] chars = num.toCharArray();

    Stack<Character> stk = new Stack<>();
    int cnt = 0;
    for (char c : chars) {
      while (!stk.empty() && stk.peek() < c && cnt < k) {
        stk.pop();
        cnt++;
      }
      stk.add(c);
    }

    while (!stk.empty() && cnt < k) {
      stk.pop();
      cnt++;
    }

    StringBuilder sb = new StringBuilder();
    while (!stk.empty()) {
      sb.append(stk.peek());
      stk.pop();
    }
    System.out.println(sb.reverse());
  }

  private static int stoi(String s) {
    return Integer.parseInt(s);
  }

}
