import java.util.*;
import java.io.*;

public class Main {
    static int N; // 당너의 개수
    static int[] alpha = new int[26];
    static int answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++){
            String str = br.readLine();

            int length = str.length();

            int order = (int) Math.pow(10, length - 1);

            for(int j = 0; j < length; j++){
                alpha[str.charAt(j) - 'A'] += order;
                order /= 10;
            }
        }

        Arrays.sort(alpha);
        answer = 0;

        for(int i = 25; i >= 16; i--){
            answer += alpha[i] * (i - 16);
        }
        System.out.println(answer);
    }
}



