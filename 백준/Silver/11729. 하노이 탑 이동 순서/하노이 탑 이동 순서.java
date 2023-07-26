import java.io.*;
import java.util.*;

public class Main {
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k;
        k = Integer.parseInt(br.readLine());
        sb.append((1<<k) - 1).append("\n");
        dfs(1, 3, k);
        System.out.println(sb);
    }

    private static void dfs(int a, int b, int n) {
        if (n == 1) {
            sb.append(a).append(" ").append(b).append("\n");
            return;
        }

        dfs(a, 6-a-b, n-1);
        sb.append(a).append(" ").append(b).append("\n");
        dfs(6-a-b, b, n-1);
    }
}
