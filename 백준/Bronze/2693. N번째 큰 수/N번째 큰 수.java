import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int i = 0; i < T; i++) {
            String[] str = br.readLine().split(" ");
            int[] arr = new int[str.length];
            for (int j = 0; j < str.length; j++) {
                arr[j] = Integer.parseInt(str[j]);
            }
            Arrays.sort(arr);
            sb.append(arr[7]).append('\n');
        }
        System.out.println(sb.toString());
    }
}