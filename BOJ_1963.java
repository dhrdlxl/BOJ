import java.util.*;
import java.io.*;
public class BOJ_1963 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int testCase = Integer.parseInt(br.readLine());

        boolean[] sieve = Sieve();

        while(testCase > 0)
        {
            testCase--;
            st = new StringTokenizer(br.readLine());

            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());

            int answer = toPrime(left, right, sieve);
            System.out.println(answer);
        }

        return;
    }

    private static int toPrime(int left, int right, boolean[] sieve)
    {
        Queue<Integer> q = new LinkedList<>();
        int[] mask = new int[10000];

        for(int index = 1000; index < 10000; index++)
            mask[index] = -1;
        q.offer(left);
        mask[left] = 0;

        while(!q.isEmpty())
        {
            int now = q.poll();
            for(int digit = 0; digit < 4; digit++)
            {
                for(int num = 0; num < 10; num++)
                {
                    int next = now;
                    for(int index = 0; index < digit; index++)
                        next /= 10;
                    
                    int digitNum = next % 10;
                    next = now;
                    int diff = num - digitNum;

                    for(int index = 0; index < digit; index++)
                        diff *= 10;
                    next += diff;

                    if(next < 1000 || mask[next] != -1 || sieve[next])
                        continue;

                    mask[next] = mask[now] + 1;
                    q.offer(next);
                }
            }
        }

        return mask[right];
    }

    private static boolean[] Sieve()
    {
        boolean[] sieve = new boolean[10000];
        for(int i = 2; i < 5000; i++)
        {
            if(sieve[i] == false)
            {
                for(int j = i + i; j < 10000; j +=i)
                {
                    sieve[j] = true;
                }
            }
        }

        return sieve;
    }
}
