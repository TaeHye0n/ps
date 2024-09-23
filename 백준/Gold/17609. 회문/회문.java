import java.util.*;
import java.io.*;

public class Main {

    // 1 <= T <= 30
    // 3 <= 문자열의 길이 <= 100,000
    static int ans;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = stoi(br.readLine());

        while (t-- > 0) {
            String s = br.readLine();
            ans = -1;
            check(0, s.length() - 1, false, s);
            System.out.println(ans);
        }
    }

    static int stoi(String s) {
        return Integer.parseInt(s);
    }

    static void check(int l, int r, boolean isPseudo, String s) {
        while (l < r) {
            if (s.charAt(l) == s.charAt(r)) {
                l++;
                r--;
            } else {
                if (isPseudo) {
                    if (ans == -1) {
                        ans = 2;
                    }
                    return;
                }
                check(l + 1, r, true, s);
                check(l, r - 1, true, s);
                return;
            }
        }
        if (isPseudo) {
            ans = 1;
        } else {
            ans = 0;
        }
    }

}
