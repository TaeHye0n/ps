import java.util.*;
import java.io.*;

public class Main{
    static int G, P;
    static int[] parent;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        G = Integer.parseInt(br.readLine());
        P = Integer.parseInt(br.readLine());
        parent = new int[G+1];
        for(int i = 1; i <= G; i++){
            parent[i] = i;
        }
        int answer = 0;
        for(int i = 0; i < P; i++){
            int airplane = Integer.parseInt(br.readLine());
            int emptyGate = find(airplane);

            if(emptyGate == 0) break;

            answer++;
            union(emptyGate, emptyGate-1);
        }
        System.out.println(answer);
    }

    static int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    static void union(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;;
        parent[x] = y;
    }
}