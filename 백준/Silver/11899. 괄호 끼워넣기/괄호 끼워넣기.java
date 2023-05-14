import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        Stack<Character> s = new Stack<>();
        int ans = 0;

        for(int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == '(') s.add(c);
            else {
                if (s.empty()) ans++;
                else s.pop();
            }
        }
        ans += s.size();
        System.out.println(ans);
    }
}