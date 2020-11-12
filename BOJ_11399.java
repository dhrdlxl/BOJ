import java.util.*;
import java.io.*;

public class BOJ_11399 {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] withdrawalTime = new int[N];

        for(int index = 0; index < N; index++)
        {
            withdrawalTime[index] = sc.nextInt();
        }

        Arrays.sort(withdrawalTime);

        int answer = withdrawalTime[0];
        for(int index = 1; index < N; index++)
        {
            withdrawalTime[index] += withdrawalTime[index - 1];
            answer += withdrawalTime[index];
        }

        System.out.println(answer);
    }    
}