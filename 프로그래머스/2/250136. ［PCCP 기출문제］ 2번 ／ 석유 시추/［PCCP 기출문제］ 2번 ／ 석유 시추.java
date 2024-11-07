import java.util.*;


class Solution {
    int[] dy = {1, -1 ,0 ,0};
    int[] dx = {0, 0, 1, -1};
    Map<Integer, Integer> group = new HashMap<>();
    public int solution(int[][] land) {
        int answer = 0;
        makeGroup(land);
        for (int i = 0; i < land[0].length; i++) {
            Set<Integer> groupNum = new HashSet<>();
            for (int j = 0; j < land.length; j++) {
                if (land[j][i] != 0) {
                    groupNum.add(land[j][i]);
                }
            }
            int score = 0;
            for (int num : groupNum) {
                score += group.get(num);
            }
            answer = Math.max(answer, score);
        }
        return answer;
    }
    
    private void makeGroup(int [][] land) {
        int n = land.length;
        int m = land[0].length;
        
        boolean[][] vi = new boolean[n + 1][m + 1];
        
        int num = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vi[i][j] && land[i][j] != 0) {
                    int cnt = 1;
                    Queue<Pair> q = new LinkedList<>();
                    vi[i][j] = true;
                    q.offer(new Pair(i, j));
                    
                    while (!q.isEmpty()) {
                        Pair cur = q.poll();
                        land[cur.y][cur.x] = num;
                        for (int w = 0; w < 4; w++) {
                            int ny = cur.y + dy[w];
                            int nx = cur.x + dx[w];
                            
                            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                            
                            if (vi[ny][nx] || land[ny][nx] == 0) continue;
                            
                            q.offer(new Pair(ny, nx));
                            vi[ny][nx] = true;
                            cnt++;
                        }
                    }
                    group.put(num++, cnt);
                }
            }
        }
        
    }
    
    private class Pair {
        int y;
        int x;
        
        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}