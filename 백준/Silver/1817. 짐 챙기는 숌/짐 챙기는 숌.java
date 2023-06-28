import java.util.*;
import java.io.*;

public class Main {
    static int n; //책의 개수
    static int m; //박스의 최대 무게
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int answer = 1;
        int boxWeight = 0;
        if(n != 0){
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++){
                int weight = Integer.parseInt(st.nextToken());
                if(boxWeight + weight <= m){
                    boxWeight += weight;
                }else{
                    answer++;
                    boxWeight = weight;
                }
            }
        }else{
            answer = 0;
        }
        System.out.println(answer);
    }
}