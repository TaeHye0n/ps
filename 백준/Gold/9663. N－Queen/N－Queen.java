import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int answer;
    static int[] col;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = stoi(br.readLine());
        col = new int[N + 1];
        answer = 0;
        recur(0);
        System.out.println(answer);
    }

    static void recur(int y) {
        if (y == N){
            answer++;
            return;
        }

        for (int i = 0; i < N; i++) {
            col[y] = i;
            if (isValid(y)) {
                recur(y + 1);
            }
        }

    }
    static boolean isValid(int y) {
        for (int i = 0; i < y; i++) {
            if (col[y] == col[i] || Math.abs(col[y] - col[i]) == y - i) return false;
        }
        return true;
    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }

}
