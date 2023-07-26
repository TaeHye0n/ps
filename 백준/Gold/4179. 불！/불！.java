import java.io.*;
import java.util.*;

public class Main {
    static final int[] dy = {1, -1, 0, 0};
    static final int[] dx = {0, 0, 1, -1};
    static class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    static int R, C;
    static String[] board;
    static int[][] dist1;
    static int[][] dist2;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        board = new String[R];
        dist1 = new int[R][C];
        dist2 = new int[R][C];

        for (int i = 0; i < R; i++) {
            Arrays.fill(dist1[i], -1);
            Arrays.fill(dist2[i], -1);
        }

        for (int i = 0; i < R; i++) {
            board[i] = br.readLine();
        }
        Queue<Pos> q1 = new LinkedList<>();
        Queue<Pos> q2 = new LinkedList<>();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                char c = board[i].charAt(j);
                if (c == 'F') {
                    q1.offer(new Pos(i, j));
                    dist1[i][j] = 0;
                }
                if (c == 'J') {
                    q2.offer(new Pos(i, j));
                    dist2[i][j] = 0;
                }
            }
        }

        bfs1(q1);
        bfs2(q2);

    }

    private static void bfs1(Queue<Pos> q1) {

        while(!q1.isEmpty()) {
            Pos cur = q1.poll();

            for (int w = 0; w < 4; w++) {
                int ny = cur.y + dy[w];
                int nx = cur.x + dx[w];

                if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;

                if (dist1[ny][nx] == -1 && board[ny].charAt(nx) != '#') {
                    q1.offer(new Pos(ny, nx));
                    dist1[ny][nx] = dist1[cur.y][cur.x] + 1;
                }
            }
        }
    }

    private static void bfs2(Queue<Pos> q2) {

        while(!q2.isEmpty()) {
            Pos cur = q2.poll();

            for (int w = 0; w < 4; w++) {
                int ny = cur.y + dy[w];
                int nx = cur.x + dx[w];

                if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
                    System.out.println(dist2[cur.y][cur.x] + 1);
                    return;
                }

                if (dist2[ny][nx] != -1 || board[ny].charAt(nx) == '#') continue;
                if (dist1[ny][nx] == -1 || dist1[ny][nx] > dist2[cur.y][cur.x] + 1) {
                    q2.offer(new Pos(ny, nx));
                    dist2[ny][nx] = dist2[cur.y][cur.x] + 1;
                }
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}