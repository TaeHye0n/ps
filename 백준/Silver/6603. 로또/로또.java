import java.util.*;
import java.io.*;

public class Main {
    static int k;
    static int[] s;
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String testCase = br.readLine();
            if(testCase.equals("0")) break;
            String[] input = testCase.split(" ");
            k = Integer.parseInt(input[0]);
            s = new int[k];
            visited = new boolean[k];
            for(int i = 0; i < k; i++){
                s[i] = Integer.parseInt(input[i+1]);
            }
            dfs(0,0);
            System.out.println();
        }
    }
    public static void dfs(int idx, int cnt){
        if(cnt == 6){
            for(int i = 0; i < k; i++){
                if(visited[i]){
                    System.out.print(s[i] + " ");
                }
            }
            System.out.println();
            return;
        }

        for(int i = idx; i < k; i++){
            visited[i] = true;
            dfs(i+1,cnt+1);
            visited[i] = false;
        }
    }
}