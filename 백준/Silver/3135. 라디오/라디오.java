import java.util.*;
import java.io.*;

public class Main {
    static int A, B;
    static int N;
    static int[] freq;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(br.readLine());
        freq = new int[N];
        for(int i = 0; i < N; i++){
            freq[i] = Integer.parseInt(br.readLine());
        }
        int diff1 = Math.abs(B-A);

        int temp = Integer.MAX_VALUE;
        for(int i = 0; i < N; i++){
            int diff2 = Math.abs(B-freq[i]);
            if(temp > diff2) temp = diff2;
        }
        temp++;

        if(temp < diff1) System.out.println(temp);
        else System.out.println(diff1);
    }
}