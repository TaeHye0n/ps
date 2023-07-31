import java.io.*;
import java.util.*;

public class Main {
    static final int N = 5;
    static final int[] dy = {1, -1, 0, 0};
    static final int[] dx = {0, 0, 1, -1};
    static char[][] board;
    static boolean[] selected;
    static int[] arr;
    static int answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        answer = 0;
        board = new char[N][N];
        selected = new boolean[N*N];
        arr = new int[7];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
        }
        func(0, 0, 0);
        System.out.println(answer);
    }

    private static void func(int cnt, int idx, int S) {
        if (cnt == 7) {
            if (S >= 4) {
                if (isAdj()) answer++;
            }
            return;
        }

        for (int i = idx; i < N*N; i++) {
            arr[cnt] = i;
            selected[i] = true;
            if (board[i/N][i%N] == 'S') func(cnt+1, i+1, S+1);
            else func(cnt+1, i+1, S);
            selected[i] = false;
        }
    }

    private static boolean isAdj() {
        boolean[] visited = new boolean[N*N];
        int cnt = 1;
        Queue<Integer> q = new LinkedList<>();
        q.offer(arr[0]);
        visited[arr[0]] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int w = 0; w < 4; w++) {
                int ny = cur/N + dy[w];
                int nx = cur%N + dx[w];

                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                if (!selected[ny*N + nx]) continue;
                if (visited[ny*N + nx]) continue;

                cnt++;
                visited[ny*N + nx] = true;
                q.offer(ny*N + nx);
            }
        }


        return cnt == 7;
    }
}
