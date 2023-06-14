import java.util.*;
import java.io.*;

public class Main{
    static int N; // 도시의 수
    static int M; // 여행 계획에 속한 도시들의 수
    static int[] parent;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        parent = new int[N+1];

        for(int i = 1; i <= N; i++){
            parent[i] = i;
        }

        for(int i = 1; i <=N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 1; j <=N; j++){
                int input = Integer.parseInt(st.nextToken());
                if(input == 1){
                    union(i,j);
                }
            }
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = find(Integer.parseInt(st.nextToken()));
        while(st.hasMoreTokens()){
            int next = Integer.parseInt(st.nextToken());

            if(start != find(next)){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }

    private static int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    private static void union(int x, int y){
        x = find(x);
        y = find(y);

        if(x < y) parent[y] = x;
        else parent[x] = y;
    }
}