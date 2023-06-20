import java.util.*;
import java.io.*;

public class Main {
    static int N; //장소의 수
    static int[] honey;
    static int answer;
    static int[] rightSum;
    static int[] leftSum;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        honey = new int[N+1];
        rightSum = new int[N+1];
        leftSum = new int[N+2];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++){
            honey[i] = Integer.parseInt(st.nextToken());
            rightSum[i] = rightSum[i-1] + honey[i];
        }


        for(int i = N; i >= 1; i--){
            leftSum[i] = leftSum[i+1] + honey[i];
        }
        answer = 0;
        int total = rightSum[N];
        // 벌통 오른쪽, 벌1 왼쪽 고정
        for(int i = 2; i <= N-1; i++){
            int val1 = total - honey[1] - honey[i];
            int val2 = total - rightSum[i];
            answer = Math.max(val1+val2, answer);
        }

        // 벌통 왼쪽, 벌1 오른쪽 고정
        for(int i = N - 1; i >= 2; i--){
            int val1 = total - honey[N] - honey[i];
            int val2 = total - leftSum[i];
            answer = Math.max(val1+val2, answer);
        }

        //벌1 왼쪽, 벌2 오른쪽 고정
        for(int i = 2; i <= N-1; i++){
            int val1 = rightSum[i] - honey[1];
            int val2 = leftSum[i] - honey[N];
            answer = Math.max(val1+val2, answer);
        }
        System.out.println(answer);
    }
}



