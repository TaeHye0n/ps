import java.util.*;
import java.io.*;

public class Main{
    static int N, M;
    static final int[] dy = {1,-1,0,0};
    static final int[] dx = {0,0,1,-1};
    static int[][] map;
    static boolean[][] visited;
    static class Room implements Comparable<Room>{
        int y;
        int x;
        int cnt;

        Room(int y, int x, int cnt){
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Room o){
            return cnt - o.cnt;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        visited = new boolean[N][M];
        for(int i = 0; i < N; i++){
            String input = br.readLine();
            for(int j = 0; j < M; j++){
                map[i][j] = Character.getNumericValue(input.charAt(j));
            }
        }
        PriorityQueue<Room> pq = new PriorityQueue<>();
        pq.offer(new Room(0,0,0));
        visited[0][0] = true;
        int ans = 0;

        while(!pq.isEmpty()){
            Room cur = pq.poll();

            if(cur.y == N-1 && cur.x == M-1){
                ans = cur.cnt;
                break;
            }

            for(int w = 0; w < 4; w++){
                int ny = cur.y + dy[w];
                int nx = cur.x + dx[w];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

                if(visited[ny][nx]) continue;

                if(map[ny][nx] == 1){
                    pq.offer(new Room(ny, nx, cur.cnt + 1));
                    visited[ny][nx] = true;
                }
                else{
                    pq.offer(new Room(ny, nx, cur.cnt));
                    visited[ny][nx] = true;
                }
            }
        }

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}