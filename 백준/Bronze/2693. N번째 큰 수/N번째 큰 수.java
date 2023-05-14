import java.util.*;
import java.io.*;

public class Main {
    static int testCase;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        testCase = Integer.parseInt(st.nextToken());

        while(testCase > 0) {
            testCase--;
            st = new StringTokenizer(br.readLine());
            int[] arr = new int[10];

            for(int i = 0; i < 10; i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);
            System.out.println(arr[7]);
        }
    }
}