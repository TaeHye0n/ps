import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] paper;
    static int[] cnt = new int[3];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        paper = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        recur(0, 0, N);
        Arrays.stream(cnt).forEach(System.out::println);
    }

    private static void recur(int y, int x, int n) {
        if (isSame(y, x, n)) {
            cnt[paper[y][x] + 1]++;
            return;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                recur(y + i * (n/3), x + j * (n/3), n/3);
            }
        }
    }

    private static boolean isSame(int y, int x, int n) {
        for (int i = y; i < y + n; i++) {
            for (int j = x; j < x + n; j++) {
                if (paper[y][x] != paper[i][j]) return false;
            }
        }
        return true;
    }
}
