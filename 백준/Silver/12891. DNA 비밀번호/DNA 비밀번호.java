import java.io.*;
import java.util.*;

public class Main {
    static int S, P;
    static String input;
    static Map<Character, Integer> constraint = new HashMap<>();
    static Map<Character, Integer> m = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        input = br.readLine();
        int answer = 0;

        st = new StringTokenizer(br.readLine());
        constraint.put('A', Integer.parseInt(st.nextToken()));
        constraint.put('C', Integer.parseInt(st.nextToken()));
        constraint.put('G', Integer.parseInt(st.nextToken()));
        constraint.put('T', Integer.parseInt(st.nextToken()));

        m.put('A', 0);
        m.put('C', 0);
        m.put('G', 0);
        m.put('T', 0);
        int left = 0, right = P;

        for (int i = left; i < right; i++) {
            m.put(input.charAt(i), m.getOrDefault(input.charAt(i), 0) + 1);
        }

        while (right <= input.length()) {
            if (check()) answer++;

            m.put(input.charAt(left), m.get(input.charAt(left)) - 1);
            if (right != input.length()) m.put(input.charAt(right), m.get(input.charAt(right)) + 1);

            left++;
            right++;

        }
        System.out.println(answer);
    }

    private static boolean check() {
        for (Character c : constraint.keySet()) {
            if (m.get(c) < constraint.get(c)) return false;
        }
        return true;
    }
}
