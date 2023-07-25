import java.io.*;
import java.util.*;

public class Main {
    static final int[] dy = {1, -1, 0, 0};
    static final int[] dx = {0, 0, 1, -1};
    static int N, M;
    static int[][] visited;
    static int[][] board;

    static class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static Queue<Pos> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        int answer = 0;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        visited = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 1 && visited[i][j] == 0) {
                    answer = Math.max(answer, bfs(new Pos(i, j)));
                    cnt++;
                }
            }
        }
        sb.append(cnt).append("\n").append(answer);
        System.out.println(sb);
    }

    private static int bfs(Pos pos) {
        q.offer(pos);
        int sum = 1;
        visited[pos.y][pos.x] = 1;
        while (!q.isEmpty()) {
            Pos cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

                if (board[ny][nx] == 1 && visited[ny][nx] == 0) {
                    q.offer(new Pos(ny, nx));
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                    sum++;
                }
            }
        }
        return sum;
    }
}