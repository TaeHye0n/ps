import java.io.*;
import java.util.*;

public class Main {
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < N; i++) {
            pq.offer(Long.parseLong(br.readLine()));
        }

        long answer = 0;
        long order = 1;
        long tip = 0;
        while (!pq.isEmpty()) {
            tip = (pq.poll() - ((order++) - 1));
            if (tip < 0) continue;
            answer += tip;
        }
        System.out.println(answer);
    }
}