import java.util.*;
import java.io.*;

public class Main{
   static int N, M;
   static int answer;
   static char[][] board;
   static boolean[][] visited, finished;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new char[N][M];
        visited = new boolean[N][M];
        finished = new boolean[N][M];
        answer = 0;

        for(int i = 0; i < N; i++){
            String str = br.readLine();
            for(int j = 0; j < M; j++){
                board[i][j] = str.charAt(j);
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!visited[i][j]) dfs(i,j);
            }
        }
        System.out.println(answer);
    }
    static void dfs(int i, int j){
        visited[i][j] = true;

        int ni = i, nj = j;
        if(board[i][j] == 'U') ni--;
        else if(board[i][j] == 'D') ni++;
        else if(board[i][j] == 'R') nj++;
        else nj--;

        if(!visited[ni][nj]) dfs(ni, nj);
        else{
            if(!finished[ni][nj]) answer++;
        }
        finished[i][j] = true;
    }
}