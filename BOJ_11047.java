import java.util.*;
import java.io.*;

public class BOJ_11047 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] changes = new int[N];
        for(int index = 0; index < N; index++)
        {
            changes[index] = Integer.parseInt(br.readLine());
        }

        int answer = 0;
        for(int index = N - 1; index >= 0; index--)
        {
            answer += (K / changes[index]);
            K %= changes[index];
        }

        System.out.println(answer);
        return;
    }
}