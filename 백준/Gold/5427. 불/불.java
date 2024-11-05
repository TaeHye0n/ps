import java.io.*;
import java.util.*;

public class Main {
  static final int[] dy = { 1, -1, 0, 0 };
  static final int[] dx = { 0, 0, 1, -1 };

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = stoi(br.readLine());

    while (t-- > 0) {
      int w = 0;
      int h = 0;
      StringTokenizer st = new StringTokenizer(br.readLine());
      w = stoi(st.nextToken());
      h = stoi(st.nextToken());
      char[][] board = new char[h][w];
      Queue<Pos> fire = new LinkedList<>();
      Queue<Pos> person = new LinkedList<>();

      int[][] visited = new int[h][w];
      int[][] visited2 = new int[h][w];

      for (int i = 0; i < h; i++) {
        String line = br.readLine();
        for (int j = 0; j < w; j++) {
          board[i][j] = line.charAt(j);
          if (line.charAt(j) == '@') {
            visited[i][j] = 1;
            person.offer(new Pos(i, j));
          } else if (line.charAt(j) == '*') {
            fire.offer(new Pos(i, j));
            visited2[i][j] = 1;
          }
        }
      }

      boolean isEscaped = false;
      int answer = 0;
      while (!isEscaped) {
        int personSize = person.size();
        if (personSize == 0) {
          System.out.println("IMPOSSIBLE");
          break;
        }

        answer++;
        int fireSize = fire.size();
        for (int i = 0; i < fireSize; i++) {
          Pos cur = fire.poll();
          for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) {
              continue;
            }
            if (visited2[ny][nx] == 1 || board[ny][nx] == '#') {
              continue;
            }
            visited2[ny][nx] = 1;
            fire.offer(new Pos(ny, nx));
          }
        }

        for (int i = 0; i < personSize; i++) {
          Pos cur = person.poll();
          for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || nx < 0 || ny >= h || nx >= w) {
              isEscaped = true;
              break;
            }

            if (visited[ny][nx] == 1 || visited2[ny][nx] == 1 ||
              board[ny][nx] == '*' ||
              board[ny][nx] == '#') {
              continue;
            }

            visited[ny][nx] = 1;
            person.offer(new Pos(ny, nx));
          }
        }
      }
      if (isEscaped) {
        System.out.println(answer);
      }
    }
  }


  static class Pos {
    int y;
    int x;

    Pos(int y, int x) {
      this.y = y;
      this.x = x;
    }
  }

  private static int stoi(String s) {
    return Integer.parseInt(s);
  }

}

