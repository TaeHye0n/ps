import java.util.*;
import java.io.*;

public class Main{
    static int n;
    static int[] arr;
    static Set<Long> set = new HashSet<>();
    static List<Long> list = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(br.readLine());
        arr = new int[10];
        for(int i = 9; i >= 0; i--){
            arr[9-i] = i;
        }
        recur(0,0);
        Collections.sort(list);

        try{
            System.out.println(list.get(n-1));
        }catch (Exception e){
            System.out.println(-1);
        }
    }
    private static void recur(long sum, int idx){
        if(!set.contains(sum)){
            set.add(sum);
            list.add(sum);
        }
        if(idx >= 10) return;

        recur(sum*10 + arr[idx], idx+1);
        recur(sum, idx+1);
    }
}