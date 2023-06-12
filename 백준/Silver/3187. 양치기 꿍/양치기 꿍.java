import java.util.*;
import java.io.*;

public class Main {
    static final int[] dy = {1, -1, 0, 0};
    static final int[] dx = {0, 0, 1, -1};
    static int R, C;
    static char[][] map;
    static int sheep, wolf;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sheep = wolf = 0;
        String[] arr = br.readLine().split(" ");
        R = Integer.parseInt(arr[0]);
        C = Integer.parseInt(arr[1]);
        map = new char[R][C];
        visited = new boolean[R][C];
        for (int i = 0; i < R; i++) {
            String str = br.readLine();
            for (int j = 0; j < C; j++) {
                map[i][j] = str.charAt(j);
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!visited[i][j] && map[i][j] != '#' && map[i][j] != '.') {
                    int sCnt = 0, wCnt = 0;
                    visited[i][j] = true;
                    Queue<Node> q = new LinkedList<>();
                    q.offer(new Node(i, j));
                    while (!q.isEmpty()) {
                        Node cur = q.poll();
                        if (map[cur.y][cur.x] == 'v') wCnt++;
                        else if (map[cur.y][cur.x] == 'k') sCnt++;

                        for (int w = 0; w < 4; w++) {
                            int ny = cur.y + dy[w];
                            int nx = cur.x + dx[w];

                            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;

                            if (visited[ny][nx] || map[ny][nx] == '#') continue;

                            q.offer(new Node(ny, nx));
                            visited[ny][nx] = true;
                        }
                    }
                    if (wCnt < sCnt) wCnt = 0;
                    else sCnt = 0;
                    sheep += sCnt;
                    wolf += wCnt;

                }
            }
        }
        System.out.println(sheep + " " + wolf);
    }

    static class Node {
        int y;
        int x;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

}