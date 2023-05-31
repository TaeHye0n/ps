import java.util.*;
import java.io.*;

public class Main {
    static int N, K;
    static int[] nums;
    static int answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        nums = new int[N];

        for(int i = 0; i < N; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0;
        int right = K-1;
        int sum = 0;
        for(int i = 0; i <= right; i++){
            sum += nums[i];
        }
        answer = sum;
        while(true){
          if(left+1 >= N || right+1 >= N) break;
          sum -= nums[left++];
          sum += nums[++right];
          answer = Math.max(answer,sum);
        }
        System.out.println(answer);
    }
}