import java.util.*;
import java.io.*;

public class Main{
    static int N; // 원생의 수
    static int K; // 조의 수
    static int[] height;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        height = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            height[i] = Integer.parseInt(st.nextToken());
        }
        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < N-1; i++){
            list.add(height[i+1] - height[i]);
        }
        Collections.sort(list);

        int ans = 0;
        for(int i = 0; i < N-K; i++){
            ans += list.get(i);
        }
        System.out.println(ans);
    }
}



