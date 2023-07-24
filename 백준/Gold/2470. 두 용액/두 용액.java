import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] amount;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        amount = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++) {
            amount[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(amount);
        int min = Integer.MAX_VALUE;
        int left = 0;
        int right = N - 1;
        int[] answer = new int[2];

        while(left < right) {
            int temp = Math.abs(amount[left] + amount[right]);
            if (temp < min) {
                min = temp;
                answer[0] = amount[left];
                answer[1] = amount[right];
            }

            if (amount[left] + amount[right] > 0) right--;
            else left++;
        }
        Arrays.stream(answer).forEach(a -> System.out.print(a + " "));
    }
}

