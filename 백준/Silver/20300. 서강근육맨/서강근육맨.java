import java.util.*;
import java.io.*;

public class Main{
    static int N;
    static Long M = Long.MIN_VALUE;
    static long[] degree;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        N = Integer.parseInt(br.readLine());
        degree = new long[N];
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N ;i++){
            degree[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(degree);

        if(degree.length % 2 == 0){
            for(int i = 0; i < (N/2); i++){
                long sum = degree[i] + degree[N-1-i] ;
                M = Math.max(sum, M);
            }
        }
        else{
            M = degree[N-1];
            for(int i = 0; i < (N/2) + 1; i++){
                long sum = degree[i] + degree[N-2-i];
                M = Math.max(sum, M);
            }
        }
        System.out.println(M);
    }
}