import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static class Word{
        int count;
        String str;

        Word(int count, String str) {
            this.count = count;
            this.str = str;
        }
    }
    static ArrayList<Word> list = new ArrayList<>();
    static Map<String, Integer> map = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++){
            String str = br.readLine();
            if(str.length() >= M) map.put(str, map.getOrDefault(str, 0) + 1);
        }

        for(String str : map.keySet()){
            list.add(new Word(map.get(str), str));
        }

        Collections.sort(list, (o1, o2) ->{
           if(o1.count == o2.count){
               if(o1.str.length() == o2.str.length()) return o1.str.compareTo(o2.str);
               return o2.str.length() - o1.str.length();
           } return o2.count - o1.count;
        });

        for(Word word : list){
            sb.append(word.str + "\n");
        }
        System.out.println(sb);
    }

}
