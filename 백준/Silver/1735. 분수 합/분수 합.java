import java.util.*;
import java.io.*;

public class Main{
    private static int stoi(String s){
        return Integer.parseInt(s);
    }
    static int[] num = new int[4];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 4; i++){
            if(i == 2) st = new StringTokenizer(br.readLine());
            num[i] = stoi(st.nextToken());
        }
        int numerator = num[0] * num[3] + num[1] * num[2];
        int denominator = num[1] * num[3];

        int gcd = GCD(denominator, numerator);
        denominator /= gcd;
        numerator /= gcd;

        bw.write(numerator + " " + denominator + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
    private static int GCD(int a, int b){
        if(b==0) return a;
        else return GCD(b, a%b);
    }
}