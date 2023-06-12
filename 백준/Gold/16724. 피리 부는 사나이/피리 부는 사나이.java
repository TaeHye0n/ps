import java.util.*;
import java.io.*;

public class Main{
   static int N, M;
   static int[] parent;
   static char[][] board;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        parent = new int[N*M];
        board = new char[N][M];

        for(int i = 0; i < N; i++){
            String str = br.readLine();
            for(int j = 0; j < M; j++){
                board[i][j] = str.charAt(j);
                parent[i*M + j] = i*M + j;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int ny = i, nx = j;
                if(board[i][j] == 'U') ny--;
                else if(board[i][j] == 'D') ny++;
                else if(board[i][j] == 'L') nx--;
                else nx++;
                int cur = i * M + j;
                int next = ny * M + nx;
                if(parent[cur] != parent[next]) union(next, cur);
            }
        }
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < N*M; i++){
            set.add(find(i));
        }
        System.out.println(set.size());
    }
    static void union(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        parent[y] = x;
    }
    static int find(int x){
        if(parent[x] == x ) return x;
        return parent[x] = find(parent[x]);
    }
}