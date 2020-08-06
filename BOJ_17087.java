import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

public class BOJ_17087 {
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int[] pos = new int[N];
        
        st = new StringTokenizer(br.readLine());
        
        for(int index = 0 ; index < N ; index++)
        {
            pos[index] = Integer.parseInt(st.nextToken()) - S;
            if(pos[index] < 0)//abs
                pos[index] *= -1;
        }

        //최대공약수 구하기.
        int gcd = pos[0];
        for(int index = 1 ; index < N; index++)
        {
            gcd = GCD(gcd, pos[index]);
        }
        bw.write(Integer.toString(gcd) + '\n');
        bw.flush();
        bw.close();
    }

    public static int GCD(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        else
        {
            return GCD(b, a%b);
        }
    }
}