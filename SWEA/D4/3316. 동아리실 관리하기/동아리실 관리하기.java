/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// double b = 1.0;               
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b);                                     // double 변수 1개 출력하는 예제
//System.out.println(g);                                     // char 변수 1개 출력하는 예제
//System.out.println(var);                             // 문자열 1개 출력하는 예제
//System.out.println(AB);                                // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
 
import java.io.*;
import java.util.*;
/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{ static final int mod = 1_000_000_007;
    static int T; //테스트 케이스
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
 
        for (int t = 1; t <= T; t++) {
            String managers = br.readLine();
            dp = new int[managers.length()][16];
            int answer = solve(managers);
            sb.append("#").append(t).append(" ").append(answer).append("\n");
        }
        System.out.println(sb);
    }
 
    private static int solve(String managers) {
        int ans = 0;
        for (int i = 0; i < managers.length(); i++) {
            int manager = 1 << (managers.charAt(i) - 'A');
 
            for (int j = 1; j < 16; j++) {
                if (i == 0) {
                    if ((j & manager) != 0  && (j & 1) != 0) { // 담당자를 포함하고 첫날엔 A가 무조건 있어야함
                        dp[i][j] = 1;
                    }
                } else {
                    if (dp[i-1][j] == 0) continue;
                    for (int k = 1; k < 16; k++) {
                        if ((j & k) != 0 && (k & manager) != 0) { //어제 나온 사람이 오늘 나오고(열쇠), 오늘 나온사람이 담당자
                            dp[i][k] = (dp[i][k] + dp[i-1][j]) % mod;
                        }
                    }
                }
            }
        }
        for (int i = 1; i < 16; i++) {
            ans = (ans + dp[managers.length()-1][i]) % mod;
        }
        return ans;
    }
}