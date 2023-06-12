import java.util.*;
import java.io.*;

public class Main{
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        TreeMap<String, Integer> treeMap = new TreeMap<>();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < N; i++){
            String[] arr = br.readLine().split("\\.");
            String str = arr[1];
            treeMap.put(str, treeMap.getOrDefault(str, 0) + 1);
        }
        while(!treeMap.isEmpty()){
            Map.Entry<String, Integer> entry = treeMap.pollFirstEntry();
            sb.append(entry.getKey()+" " + entry.getValue() + "\n");
        }
        System.out.println(sb.toString());
    }

}