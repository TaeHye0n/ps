import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] board;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N+1][N+1];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < N; j++) {
                board[i][j] = str.charAt(j) - '0';
            }
        }
        func(0, 0, N);
        System.out.println(sb.toString());

    }

    private static void func(int y, int x, int n) {
        if (n == 1) {
            sb.append(board[y][x]);
            return;
        }

        boolean zero = true, one = true;
        for (int i = y; i < y + n; i++) {
            for (int j = x; j < x + n; j++) {
                if (board[i][j] == 1) zero = false;
                else one = false;
            }
        }

        if (zero) sb.append(0);
        else if (one) sb.append(1);
        else {
            sb.append("(");
            func(y, x, n/2);
            func(y, x + n/2, n/2);
            func(y + n/2, x, n/2);
            func(y + n/2, x + n/2, n/2);
            sb.append(")");
        }
    }

}
