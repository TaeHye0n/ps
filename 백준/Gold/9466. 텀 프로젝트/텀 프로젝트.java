import java.util.*;
import java.io.*;

public class Main{
    static int T;
    static int n;
    static boolean[] visited;
    static boolean[] finished;
    static int[] arr;
    static int cnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = null;
        T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n+1];
            visited = new boolean[n+1];
            finished = new boolean[n+1];
            cnt = 0;

            st = new StringTokenizer(br.readLine());
            for(int i = 1; i <= n; i++){
                if(finished[i]) continue;
                arr[i] = Integer.parseInt(st.nextToken());
            }

            for(int i = 1; i <= n; i++){
                dfs(i);
            }
            
            System.out.println(n - cnt);
        }
    }

    private static void dfs(int cur){
        if(finished[cur]) return;
        if(visited[cur]){
            finished[cur] = true;
            cnt++;
        }

        visited[cur] = true;
        dfs(arr[cur]);
        finished[cur] = true;
        visited[cur] = false;
    }
}