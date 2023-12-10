import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    static final int[] dy = {1, -1, 0, 0};
    static final int[] dx = {0, 0, 1, -1};
    static boolean visited[][];

    static class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public int[] solution(String[] maps) {
        List<Integer> answer = new ArrayList<>();
        visited = new boolean[maps.length][maps[0].length()];

        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (maps[i].charAt(j) != 'X' && !visited[i][j])
                answer.add(bfs(maps, new Pos(i, j)));
            }
        }
        if (answer.size() == 0) {
            return new int[]{-1};
        }
        return answer.stream().mapToInt(Integer::intValue).sorted().toArray();
    }

    private int bfs(String[] maps, Pos pos) {
        Queue<Pos> q = new LinkedList<>();
        q.offer(pos);
        int cnt = maps[pos.y].charAt(pos.x) - '0';
        visited[pos.y][pos.x] = true;

        while (!q.isEmpty()) {
            Pos cur = q.poll();

            for (int d = 0; d < 4; d++) {
                int ny = cur.y + dy[d];
                int nx = cur.x + dx[d];

                if (ny < 0 || nx < 0 || ny >= maps.length || nx >= maps[0].length()) {
                    continue;
                }

                if (maps[ny].charAt(nx) != 'X' && !visited[ny][nx]) {
                    cnt += maps[ny].charAt(nx) - '0';
                    q.offer(new Pos(ny, nx));
                    visited[ny][nx] = true;
                }
            }
        }
        return cnt;
    }
}