import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] nums;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        nums = new int[N];

        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(nums);

        int min = Integer.MAX_VALUE;
        int right = 0;
        for (int left = 0; left < N; left++) {
            while (right < N && nums[right] - nums[left] < M) right++;
            if (right == N) break;
            min = Math.min(min, nums[right] - nums[left]);
        }
        System.out.println(min);
    }
}

