import java.util.*;
import java.io.*;

class Solution {
    static final int[] dy = {1,-1,0,0};
    static final int[] dx = {0,0,1,-1};
    static int M, N;
    static boolean[][] visited;
    static int[][] pic;
    static class Space{
        int y,x;
        
        public Space(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    public int[] solution(int m, int n, int[][] picture) {
        M = m;
        N = n;
        pic = picture;
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        visited = new boolean[M+1][N+1];
        
        for(int i = 0; i < picture.length; i++){
            for(int j = 0; j < picture[i].length; j++){
                if(!visited[i][j] && pic[i][j] != 0){
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, bfs(i, j, pic[i][j]));
                    numberOfArea++;
                }
            }
        }
        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
    
    private static int bfs(int y, int x, int std){
        int cnt = 0;
        Queue<Space> q = new LinkedList<>();
        q.offer(new Space(y,x));
        visited[y][x] = true;
        
        while(!q.isEmpty()){
            int curY = q.peek().y;
            int curX = q.peek().x;
            q.remove();
            
            cnt++;
            for(int w = 0; w < 4; w++){
                int ny = curY + dy[w];
                int nx = curX + dx[w];
                
                if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
                
                if(!visited[ny][nx] && pic[ny][nx] == std){
                    visited[ny][nx] = true;
                    q.offer(new Space(ny,nx));
                }
            }
        }
        return cnt;
    }
}