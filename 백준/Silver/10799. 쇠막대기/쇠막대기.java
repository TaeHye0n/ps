import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        Stack<Character> stack = new Stack<>();
        int answer = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') stack.push(c);
            else {
                if (s.charAt(i-1) == '(') {
                    stack.pop();
                    answer += stack.size();
                }
                else {
                    answer++;
                    stack.pop();
                }
            }
        }
        System.out.println(answer);
    }
}