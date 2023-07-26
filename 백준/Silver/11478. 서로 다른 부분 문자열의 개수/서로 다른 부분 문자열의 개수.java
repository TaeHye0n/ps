import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        Set<String> set = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            for (int len = 1; len + i <= s.length(); len++) {
                set.add(s.substring(i, i + len));
            }
        }
        System.out.println(set.size());
    }
}
