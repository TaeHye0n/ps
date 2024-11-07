import java.util.*;
import java.io.*;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = stoi(br.readLine());
    PriorityQueue<Integer> cards = new PriorityQueue<>();
    for (int i = 0; i < N; i++) {
        cards.offer(stoi(br.readLine()));
    }

    int answer = 0;
    while (cards.size() > 1) {
        int num1 = cards.poll();
        int num2 = cards.poll();
        answer += (num1 + num2);

        cards.offer(num1 + num2);
    }
    System.out.println(answer);

  }

  private static int stoi(String s) {
    return Integer.parseInt(s);
  }

}
