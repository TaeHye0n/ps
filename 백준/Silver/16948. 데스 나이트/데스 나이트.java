import java.io.*;
import java.util.*;

public class Main {
    static final int[] dy = {-2, -2, 0, 0, 2, 2};
    static final int[] dx = {-1, 1, -2, 2, -1, 1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] visited = new int[N+1][N+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r1 = Integer.parseInt(st.nextToken());
        int c1 = Integer.parseInt(st.nextToken());
        int r2 = Integer.parseInt(st.nextToken());
        int c2 = Integer.parseInt(st.nextToken());

        Queue<Pos> q = new LinkedList<>();
        visited[r1][c1] = 1;
        q.offer(new Pos(r1,c1));
        while (!q.isEmpty()) {
            Pos cur = q.poll();

            if (cur.y == r2 && cur.x == c2) break;

            for (int w = 0; w < 6; w++) {
                int ny = cur.y + dy[w];
                int nx = cur.x + dx[w];

                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                if (visited[ny][nx] == 0) {
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                    q.offer(new Pos(ny, nx));
                }
            }
        }

        if (visited[r2][c2] == 0) System.out.println(-1);
        else System.out.println(visited[r2][c2]-1);
    }

    static class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}