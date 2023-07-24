import java.io.*;
import java.util.*;

public class Main {
    static int N, S;
    static int[] nums;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(br.readLine());
        N = Integer.parseInt(token.nextToken());
        S = Integer.parseInt(token.nextToken());
        nums = new int[N];

        token = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(token.nextToken());
        }

        int answer = Integer.MAX_VALUE;
        int right = 0;
        int sum = nums[0];
        for (int left = 0; left < N; left++) {
            while (right < N && sum < S) {
                right++;
                if(right != N) sum += nums[right];
            }
            if (right == N) break;
            answer = Math.min(answer, right - left + 1);
            sum -= nums[left];
        }
        answer = answer == Integer.MAX_VALUE ? 0 : answer;
        System.out.println(answer);
    }
}