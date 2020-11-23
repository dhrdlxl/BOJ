import java.io.*;
import java.util.*;

public class BOJ_2875 {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();
        sc.close();

        K -= (N % 2);
        if(N / 2 > M)
        {
            K -= (N / 2 - M) * 2;
            N -= (N / 2 - M) * 2;
        }
        else if(N / 2 < M)
        {
            K -= (M - N / 2);
            M -= (M - N / 2);
        }

        while(K > 0)
        {
            K -= 3;
            M--;
        }

        System.out.println(M);
    }    
}