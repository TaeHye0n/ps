import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        BigInteger bigInteger = new BigInteger("2");
        bigInteger = bigInteger.pow(N).subtract(BigInteger.ONE);
        sb.append(bigInteger).append("\n");
        if(N <= 20){
            hanoi(N, 1, 3, 2);
        }
        System.out.println(sb.toString());
    }
    private static void hanoi(int N, int from, int to, int via){
        if(N==1){
            sb.append(from).append(" ").append(to).append("\n");
            return;
        }
        hanoi(N-1, from, via, to);
        sb.append(from).append(" ").append(to).append("\n");
        hanoi(N-1, via, to, from);
    }
}