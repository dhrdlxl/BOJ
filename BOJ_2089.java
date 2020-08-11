import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class BOJ_2089 {
    public static void minusBinary(BufferedWriter bw, int num) throws IOException
    {
        if(num == 0)
        {
            return;
        }
        if(num % -2 == 0)
        {
            minusBinary(bw, num / -2);
            bw.write('0');
            return;
        }
        else
        {
            if(num >= 0)
            {
                minusBinary(bw, num / -2);
            }
            else
            {
                minusBinary(bw, (num - 1) / -2);
            }
            bw.write('1');
            return;
        }
    }
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        if(N == 0)
        {
            bw.write('0');
        }
        else
        {
            minusBinary(bw, N);
        }

        bw.close();
    }    
}