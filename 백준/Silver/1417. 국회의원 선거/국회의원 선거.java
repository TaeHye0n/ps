import java.util.*;
import java.io.*;

public class Main {
    static int N; //후보의 수
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); //득표수
    static int myCount; //다솜이의 득표수
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        myCount = Integer.parseInt(br.readLine());
        for(int i = 1; i < N; i++){
            pq.offer(Integer.parseInt(br.readLine()));
        }

        int answer = 0;

        while(true){
            if(pq.isEmpty()) break;
            int top = pq.poll();
            if(top >= myCount){
                top--;
                myCount++;
                answer++;
                pq.offer(top);
            }
            else break;
        }
        System.out.println(answer);
    }
}