import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] board;
    static int[] answer = new int[2];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N+1][N+1];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        recur(0, 0, N);
        Arrays.stream(answer).forEach(System.out::println);

    }

    private static void recur(int y, int x, int n) {
        if (isSame(y, x, n)) {
            answer[board[y][x]]++;
            return;
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                recur(y + i * n / 2, x + j * n / 2, n / 2);
            }
        }
    }

    private static boolean isSame(int y, int x, int n) {
        for (int i = y; i < y + n; i++) {
            for (int j = x; j < x + n; j++) {
                if (board[y][x] != board[i][j]) return false;
            }
        }
        return true;
    }

}
