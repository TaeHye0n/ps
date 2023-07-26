import java.io.*;
import java.util.*;

public class Main {
    long cnt = 0;
    long answer = 1L;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());
        long C = Long.parseLong(st.nextToken());
        System.out.println(dfs(A, B, C));
    }

    private static long dfs(long a, long b, long c) {
        if (b == 1) return a % c;
        long value = dfs(a, b/2, c);
        value = value * value % c;
        if (b % 2 ==0) return value;
        else return value * a % c;
    }
}