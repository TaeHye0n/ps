import java.io.*;
import java.util.*;

public class Main {
    static int N, L;
    static int left, right;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(token.nextToken());
        L = Integer.parseInt(token.nextToken());

       while (true) {
           int min = N/L - ((L-1)/2);
           if (min < 0 || L > 100) {
               System.out.println(-1);
               return;
           }

           int sum = (min*2+L-1)*L/2;

           if (sum == N) {
               for (int i = 0; i < L; i++) {
                    sb.append(min+i).append(" ");
               }
               break;
           }
           L++;
       }
        System.out.println(sb);
    }
}