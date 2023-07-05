import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] myCard;
    static int M;
    static int[] cards;
    static int[] answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        myCard = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            myCard[i] = Integer.parseInt(st.nextToken());
        }

        M = Integer.parseInt(br.readLine());
        cards = new int[M];
        answer = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            cards[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(myCard);

        int idx = 0;
        for (int num : cards) {
            int left = 0;
            int right = N-1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (myCard[mid] < num) left = mid + 1;
                else {
                    if (myCard[mid] == num){
                        answer[idx] = 1;
                        break;
                    }
                    right = mid - 1;
                }
            }
            idx++;
        }
        for (int i = 0; i < M; i++) {
            sb.append(answer[i]).append(" ");
        }
        System.out.println(sb);
    }
}
