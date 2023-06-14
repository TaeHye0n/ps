import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] customers = new int[M];
        int answer = 0;
        int answer2 = 0;
        for(int i = 0; i < M; i++){
            customers[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(customers);

        for(int i = M-1; i >=0 ;i--){
            int sum = 0;
            int cnt = 0;
            int cost = customers[i];
            for(int j = M-1; j >= 0; j--){
                if(customers[j] >= cost){
                    cnt++;
                    sum += cost;
                }
                if(cnt == N) break;
            }
            if(answer <= sum) {
                answer = sum;
                answer2 = cost;
            }
        }
        sb.append(answer2).append(" ").append(answer);
        System.out.println(sb.toString());
    }
}

