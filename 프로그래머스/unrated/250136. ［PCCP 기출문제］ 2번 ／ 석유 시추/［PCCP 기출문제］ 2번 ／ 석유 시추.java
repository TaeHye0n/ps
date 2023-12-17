import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

/*
2. [PCCP 기출문제] 2번 / 석유 시추 https://school.programmers.co.kr/learn/courses/30/lessons/250136
 */
public class Solution {
    static final int[] dy = {1, -1, 0, 0};
    static final int[] dx = {0, 0, 1, -1};
    static int n, m;
    static int oliId[][];
    static boolean visited[][];
    static Map<Integer, Integer> oliAmount = new HashMap<>();

    public int solution(int[][] land) {
        n = land.length;
        m = land[0].length;
        oliId = new int[n][m];
        visited = new boolean[n][m];

        int id = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && land[i][j] == 1) {
                    int amount = bfs(i, j, id, land);
                    oliAmount.put(id++, amount);
                }
            }
        }

        int[] oilSum = new int[m];
        for (int i = 0; i < m; i++) {
            Set<Integer> idSet = new HashSet<>();
            for (int j = 0; j < n; j++) {
                if (land[j][i] == 1) {
                    idSet.add(oliId[j][i]);
                }
            }

            for (int k : idSet) {
                oilSum[i] += oliAmount.get(k);
            }
        }
        return Arrays.stream(oilSum).max().getAsInt();
    }

    private int bfs(int y, int x, int id, int[][] land) {
        Queue<int[]> q = new LinkedList<>();
        visited[y][x] = true;
        oliId[y][x] = id;
        q.offer(new int[]{y, x});
        int size = 1;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int w = 0; w < 4; w++) {
                int ny = cur[0] + dy[w];
                int nx = cur[1] + dx[w];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                    continue;
                }

                if (!visited[ny][nx] && land[ny][nx] == 1) {
                    q.offer(new int[]{ny, nx});
                    visited[ny][nx] = true;
                    oliId[ny][nx] = id;
                    size++;
                }
            }
        }
        return size;
    }
}
