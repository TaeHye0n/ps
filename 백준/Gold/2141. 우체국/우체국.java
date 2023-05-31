import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static long total = 0;
    static Town[] town;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        town = new Town[N];
        StringTokenizer st = null;

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            long X = Long.parseLong(st.nextToken());
            long A = Long.parseLong(st.nextToken());
            town[i] = new Town(X, A);
            total += A;
        }
        Arrays.sort(town);
        long cnt = 0;
        for (Town t : town) {
            cnt += t.A;
            if(cnt >= (total+1)/2){
                System.out.println(t.X);
                break;
            }
        }
    }

    static class Town implements Comparable<Town>{
        long X, A;

        public Town(long X, long A) {
            this.X = X;
            this.A = A;
        }

        @Override
        public int compareTo(Town o){
            if(this.X == o.X) return (int) (this.X - o.A);
            return (int) (this.X - o.X);
        }
    }
}