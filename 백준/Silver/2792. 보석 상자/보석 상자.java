import java.util.*;
import java.io.*;

public class Main {
    static int N; //아이들의 수
    static int M; //색상의 수
    static int[] colors;
    static int left, right;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        colors = new int[M];
        left = 1;
        for(int i = 0; i < M; i++){
            colors[i] = Integer.parseInt(br.readLine());
            right = Math.max(colors[i], right);
        }

        int answer = Integer.MAX_VALUE;

        while(left <= right){
            int mid = (left+right)/2;
            if(canSpread(mid)){
                answer = Math.min(answer, mid);
                right = mid - 1;
            } else left = mid + 1;
        }
        System.out.println(answer);
    }

    private static boolean canSpread(int mid){
        int num = 0;
        for(int i = 0; i < M; i++) {
            num += colors[i] / mid;
            if(colors[i] % mid != 0) num++;
        }
        return N >= num;
    }
}