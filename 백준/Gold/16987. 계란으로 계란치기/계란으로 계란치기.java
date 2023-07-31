import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] s;
    static int[] w;
    static int answer;
    static int cnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        s = new int[N+1];
        w = new int[N+1];
        answer = 0;
        cnt = 0;
        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");
            s[i] = Integer.parseInt(str[0]);
            w[i] = Integer.parseInt(str[1]);
        }
        func(0);
        System.out.println(answer);
    }

    public static void func(int st) {
        if (st == N) {
            answer = Math.max(answer, cnt);
            return;
        }

        if (s[st] <= 0 || cnt >= N-1) {
            func(st + 1);
            return;
        }

        for (int i = 0; i < N; i++) {
            if (i == st || s[i] <= 0) continue;
            s[i] -= w[st];
            s[st] -= w[i];
            if (s[i] <= 0) cnt++;
            if (s[st] <= 0) cnt++;
            func(st + 1);
            if (s[i] <= 0) cnt--;
            if (s[st] <= 0) cnt--;
            s[i] += w[st];
            s[st] += w[i];
        }
    }
}
