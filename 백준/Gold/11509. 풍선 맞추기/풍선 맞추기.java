import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int answer = 0;
        int[] cnt = new int[1000002];

        for (int i = 0; i < N; i++) {
            int h = Integer.parseInt(st.nextToken());
            if (cnt[h+1] > 0) cnt[h+1]--;
            else answer++;
            cnt[h]++;
        }
        System.out.println(answer);
    }
}