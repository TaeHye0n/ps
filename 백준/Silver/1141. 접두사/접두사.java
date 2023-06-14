import java.util.*;
import java.io.*;

public class Main{
    static int N;
    static String[] words;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        words = new String[N];

        for(int i = 0; i < N; i++){
            words[i] = br.readLine();
        }

        Arrays.sort(words);

        int length = words.length;
        for(int i = 0; i < N-1; i++){
            if(isPrefix(words[i], words[i+1])) length--;
        }
        System.out.println(length);
    }
    private static boolean isPrefix (String s1, String s2){
        int length1 = s1.length();

        for(int i = 0; i < length1; i++){
            if(s1.charAt(i) != s2.charAt(i)) return false;
        }
        return true;
    }
}