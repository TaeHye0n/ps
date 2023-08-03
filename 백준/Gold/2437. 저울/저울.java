import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).sorted().toArray();

        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (sum + 1 < arr[i]) break;
            sum += arr[i];
        }
        System.out.println(sum+1);
    }
}