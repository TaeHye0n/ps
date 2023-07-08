import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] color = new int[2];

        String input = br.readLine();
        char before = ' ';
        for (int i = 0; i < N; i++) {
            char cur = input.charAt(i);
            if (cur != before) {
                if (cur == 'R') color[0]++;
                else color[1]++;
            }
            before = cur;
        }

        int answer = 1;
        answer += Math.min(color[0], color[1]);
        System.out.println(answer);
    }
}