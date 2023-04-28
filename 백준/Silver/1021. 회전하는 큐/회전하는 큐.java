import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static StringBuilder sb = new StringBuilder();
    static int count = 0;
    static LinkedList<Integer> dq = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[M];

        for(int i = 0; i < M; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i <= N; i++){
            dq.add(i);
        }

        for(int i = 0; i < M; i++){
            int temp = arr[i];
            boolean flag = false;
            for(int j = 0; j <= dq.size()/2; j++){
                if(temp == dq.get(j)){
                    flag = true;
                    break;
                }
            }
            if(flag){
                while(temp != dq.get(0)){
                    dq.addLast(dq.pollFirst());
                    count++;
                }
            }else{
                while(temp != dq.get(0)){
                    dq.addFirst(dq.pollLast());
                    count++;
                }
            }
            dq.poll();
        }
        System.out.println(count);
    }
}
