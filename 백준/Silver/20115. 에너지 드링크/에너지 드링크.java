import java.util.*;
import java.io.*;

public class Main{
    static int N;
    static double answer;
    static int[] drinks;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        drinks = new int[N];

        for(int i = 0; i < N; i++){
            drinks[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(drinks);
        answer = drinks[N-1];
        for(int i = N-2; i >=0; i--){
            answer = answer + drinks[i]/(double) 2;
        }
        System.out.println(answer);
    }
}

