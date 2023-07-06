import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int[] alpha = new int[26];

        for (int i = 0; i < input.length(); i++) {
            alpha[input.charAt(i) - 'A']++;
        }

        int oddCount = 0;
        for (int i : alpha) {
            if(i % 2 != 0) oddCount++;
        }

        if(oddCount > 1) System.out.println("I'm Sorry Hansoo");
        else{
            int oddIdx = -1;
            StringBuilder front = new StringBuilder();
            for (int i = 0; i < alpha.length; i++) {
                if (alpha[i] % 2 != 0) oddIdx = i;
                for (int j = 0; j < alpha[i] / 2; j++) {
                    front.append((char) (i + 'A'));
                }
            }
                StringBuilder answer = new StringBuilder();
                if (oddIdx != -1) {
                    answer.append(front.toString()).
                            append((char) (oddIdx + 'A')).
                            append(front.reverse().toString());
                } else {
                    answer.append(front.toString()).append(front.reverse().toString());
                }
                System.out.println(answer);
        }
    }
}