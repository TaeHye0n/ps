import java.util.*;
import java.io.*;

public class Main {
    static int N; // 사과나무의 개수
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int sum = 0;
        int oddDays = 0;
        for (int i = 0; i < N; i++) {
            int tree = Integer.parseInt(st.nextToken());
            sum += tree;
            if(tree % 2 == 1) oddDays++;
        }

        int days = sum / 3;

        if(oddDays <= days && sum % 3 == 0) System.out.println("YES");
        else System.out.println("NO");
    }
}



