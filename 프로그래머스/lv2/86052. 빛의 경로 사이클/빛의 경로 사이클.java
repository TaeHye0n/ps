import java.util.*;
import java.io.*;


class Solution {
    static final int[] dy = {-1,0,1,0};
    static final int[] dx = {0,1,0,-1};
    static int N, M;
    static boolean[][][] visited;
    public int[] solution(String[] grid) {
        List<Integer> answer = new ArrayList<>();
        
        N = grid.length; // 행 길이
        M = grid[0].length(); // 열 길이
        
        visited = new boolean[N][M][4];
        for(int i = 0; i < N ;i++){
            for(int j = 0; j < M; j++){
                for(int d = 0; d < 4; d++){
                    if(!visited[i][j][d])
                    answer.add(lightMove(grid,i,j,d));
                }
            }
        }
        
        return answer.stream().sorted().mapToInt(i->i).toArray();
    }
    
    public static int lightMove(String[] grid, int y, int x, int d){
        int cnt = 0;
        
        while(true){
            if(visited[y][x][d]) break;
            cnt++;
            visited[y][x][d] = true;
            
            if(grid[y].charAt(x) == 'L'){
                d = d-1;
                if(d<0) d = 3;
            }
            else if(grid[y].charAt(x) == 'R'){
               d = (1+d)%4;
            }
            
            y = (y + dy[d] + N) % N;
            x = (x + dx[d] + M) % M;
        }
        return cnt;
    }
}