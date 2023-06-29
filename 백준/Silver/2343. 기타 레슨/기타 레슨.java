import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] lectures;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        lectures = new int[N];

        st = new StringTokenizer(br.readLine());
        int left = 0;
        int right = 0;
        for (int i = 0; i < N; i++) {
            lectures[i] = Integer.parseInt(st.nextToken());
            right += lectures[i];
            left = Math.max(left, lectures[i]);
        }
        int answer = Integer.MAX_VALUE;

        while (left <= right) {
            int mid = (left + right) / 2;
            int count = 1;
            int sum = 0;
            for (int lecture : lectures) {
                sum += lecture;
                if (sum > mid) {
                    sum = lecture;
                    count++;
                }
            }
            if (count > M) left = mid + 1;
            else {
                answer = Math.min(answer, mid);
                right = mid - 1;
            }
        }
        System.out.println(answer);

    }
}