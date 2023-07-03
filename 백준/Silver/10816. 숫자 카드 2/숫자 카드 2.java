import java.io.*;
import java.util.*;

public class Main {
    static int N; //숫자 카드의 개수
    static int M; //몇개 가지고 있는지 구해야할 숫자카드의 개수
    static int[] nums;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        nums = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }
        M = Integer.parseInt(br.readLine());

        Arrays.sort(nums);
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++){
            int target = Integer.parseInt(st.nextToken());
            sb.append(upperBound(target) - lowerBound(target)).append(" ");
        }
        System.out.println(sb);
    }
    private static int lowerBound(int target){
        int left = 0;
        int right = N;
        while(left < right){
            int mid = (left + right) / 2;

            if(target <= nums[mid]) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    private static int upperBound(int target){
        int left = 0;
        int right = N;

        while(left < right) {
            int mid = (left + right) / 2;

            if (target < nums[mid]) right = mid;
            else left = mid + 1;
        }
        return right;
    }
}
