import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class BOJ_17103 {
    static final int maxN = 1000001; 
    public static void eratosthenes(boolean[] checkPrime)
    {
        for(int index = 2; index < maxN ; index++)
        {
            for(int check = index + index; check < maxN; check += index)
            {
                checkPrime[check] = false;
            }
        }
    }
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        boolean[] checkPrime = new boolean[maxN];
        for(int index = 0; index < maxN; index++)
        {
            checkPrime[index] = true;
        }
        eratosthenes(checkPrime);

        int testCase = Integer.parseInt(br.readLine());
        for(int index = 1; index <= testCase; index++)
        {
            int N = Integer.parseInt(br.readLine());
            int answer = 0;

            for(int Num = 2; Num <= N / 2; Num++)
            {
                if(checkPrime[Num] && checkPrime[N - Num])
                {
                    answer++;
                }
            }

            bw.write(Integer.toString(answer) + '\n');
        }
        bw.flush();
        bw.close();
    }
}