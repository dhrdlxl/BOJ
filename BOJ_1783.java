import java.io.*;
import java.util.*;

public class BOJ_1783 {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.close();

        int answer = 0;
        if(N == 1)
        {
            answer = 1;
        }
        else if(N == 2)
        {
            answer = (M + 1) / 2;
            if(answer > 4)
            {
                answer = 4;
            }
        }
        else if(N > 2)
        {
            answer = M;
            if(answer > 4)
            {
                if(M <= 6)
                {
                    answer = 4;
                }
                else
                {
                    answer -= 2;
                }
            }
        }

        System.out.println(answer);
    }    
}