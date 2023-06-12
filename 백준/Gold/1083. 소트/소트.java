import java.util.*;
import java.io.*;

public class Main {
    static int N, S;
    static int[] nums;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < N; i++){
            list.add(Integer.parseInt(st.nextToken()));
        }
        S = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++){
            int max = 0, maxIdx = 0;
            if(S <= 0) break;
            for(int j = i; j < N && j <= S + i; j++){
                if(max <= list.get(j)){
                    max = list.get(j);
                    maxIdx = j;
                }
            }
            list.remove(maxIdx);
            list.add(i, max);

            S = S - (maxIdx - i);
        }

        StringBuilder sb = new StringBuilder();
        for(int num : list){
            sb.append(num + " ");
        }
        System.out.println(sb);
    }
}