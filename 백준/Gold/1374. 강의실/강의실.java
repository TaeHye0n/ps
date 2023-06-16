import java.util.*;
import java.io.*;

public class Main {
    static int N; // 강의의 개수
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        N = stoi(br.readLine());
        int[] stArr = new int[N];
        int[] edArr = new int[N];
        int answer = 0;
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int num = stoi(st.nextToken());
            int start = stoi(st.nextToken());
            int end = stoi(st.nextToken());
            stArr[i] = start;
            edArr[i] = end;
        }
        Arrays.sort(stArr);
        Arrays.sort(edArr);
        for(int i = 0, r = 0, sz = 0; i < N; i++){
            sz++;
            while(edArr[r] <= stArr[i]){
                r++;
                sz--;
            }
            answer = Math.max(answer, sz);
        }
        System.out.println(answer);
    }
    private static int stoi(String s){
        return Integer.parseInt(s);
    }

}