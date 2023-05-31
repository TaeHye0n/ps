import java.util.*;
import java.io.*;

public class Main {
    static int answer;
    static int N;
    static int[] alphabet;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String standard = br.readLine();
        alphabet = new int[26];
        answer = 0;

        for(int i = 0; i < standard.length(); i++){
            alphabet[standard.charAt(i) - 'A']++;
        }

        for(int i = 0; i < N-1; i++){
            String str = br.readLine();
            int[] copyAlphabet = alphabet.clone();
            int cnt = 0;
            for(int j = 0; j < str.length(); j++){
                if(copyAlphabet[str.charAt(j) - 'A'] > 0){
                    cnt++;
                    copyAlphabet[str.charAt(j) - 'A']--;
                }
            }
            if(standard.length() == str.length()+1 && cnt == str.length()) answer++;
            else if(standard.length() == str.length() && (cnt == standard.length() || cnt == standard.length()-1)) answer++;
            else if(standard.length() == str.length()-1 && cnt == standard.length()) answer++;
        }
        System.out.println(answer);
    }
}