import java.util.*;
import java.io.*;

public class Main {
    static int N, S, answer;
    static int[] sequence;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        answer = 0;
        sequence = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            sequence[i] = Integer.parseInt(st.nextToken());
        }
        dfs(0,0);
        if(S==0)System.out.println(answer-1);
        else System.out.println(answer);
    }

    private static void dfs(int sum, int idx){
        if(idx == N){
            if(sum == S) answer++;
            return;
        }

        dfs(sum+sequence[idx], idx+1);
        dfs(sum, idx+1);
    }
}