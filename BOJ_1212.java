import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class BOJ_1212 {
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String octal = br.readLine();
        boolean check = false;

        if(octal.length() == 1 && octal.charAt(0) == '0')
        {
            bw.write('0');
        }
        
        for(int index = 0; index < octal.length(); index++)
        {
            int num = octal.charAt(index) - '0';
            for(int shift = 2; shift >= 0; shift--)
            {
                if((num & (1 << shift)) > 0)
                {
                    bw.write('1');
                    check = true;
                }
                else
                {
                    if(check)
                        bw.write('0');
                }
            }
        }
        bw.flush();
        bw.close();
    }
}