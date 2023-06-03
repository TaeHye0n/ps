import java.util.*;
import java.io.*;

public class Main{
    static int[] info;
    static int[] visited;
    static int ans;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        info = new int[5];
        ans = 0;

        for(int i = 0; i < 5; i++){
            info[i] = Integer.parseInt(st.nextToken());
        }
        visited = new int[info[0]+1];
        info[4] = -info[4];

        Queue<Integer> q = new LinkedList<>();
        q.add(info[1]);
        visited[info[1]] = 1;
        if(info[1] == info[2]){
            System.out.println(ans);
            return;
        }
        while(!q.isEmpty()){
            int cur = q.poll();
            if(cur == info[2]){
                ans = visited[cur] - 1;
                break;
            }

            for(int i = 3; i <= 4;i++){
                int next = cur + info[i];

                if(next < 1 || next > info[0]) continue;

                if(visited[next] == 0){
                    visited[next] = visited[cur] + 1;
                    q.add(next);
                }
            }

        }
        if(ans == 0) System.out.println("use the stairs");
        else System.out.println(ans);
    }
}