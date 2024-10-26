import java.util.*;
import java.io.*;

public class Main {

    static int n;
    static List<String> board = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = stoi(br.readLine());

        for (int i = 0; i < n; i++) {
            board.add(br.readLine());
        }

        recur(0, 0, n);
        System.out.println(sb);
    }

    static void recur(int y, int x, int k) {
        if (k == 1) {
            sb.append(board.get(y).charAt(x));
            return;
        }

        boolean one = true;
        boolean zero = true;
        for (int i = y; i < y + k; i++) {
            for (int j = x; j < x + k; j++) {
                if (!zero && !one) break;
                if (board.get(i).charAt(j) == '0') one = false;
                else if (board.get(i).charAt(j) == '1') zero = false;
            }
        }

        if (zero) sb.append(0);
        else if (one) sb.append(1);
        else {
            sb.append("(");
            recur(y, x, k / 2);
            recur(y, x + k / 2, k / 2);
            recur(y + k / 2, x, k / 2);
            recur(y + k / 2, x + k / 2, k / 2);
            sb.append(")");
        }
    }
    static int stoi(String s) {
        return Integer.parseInt(s);
    }

}
