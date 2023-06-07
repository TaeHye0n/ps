import java.util.*;
import java.io.*;

public class Main{
    static int n, m;
    static int[][] dist;
    static int[][] ans;
    static final int INF = 987654321;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        dist = new int[n+1][m+1];
        ans =  new int[n+1][m+1];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                if(i==j) dist[i][j] = 0;
                else dist[i][j] = INF;
                ans[i][j] = j;
            }
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            dist[a][b] = dist[b][a] = Math.min(dist[a][b], c);
        }

        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <=n ;j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                        ans[i][j] = ans[i][k];
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) bw.append("- ");
                else{
                    bw.append(ans[i][j] + " ");
                }
            }
            bw.append("\n");
        }
        bw.write("\n");
        bw.flush();
        bw.close();
        br.close();
    }
}