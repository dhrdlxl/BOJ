import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Stack;

public class BOJ_1373 {
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String binaryNumber = br.readLine();
        Stack<Character> st = new Stack<>();

        for(int index = binaryNumber.length() - 1 ; index >= 0;)
        {
            int sum = 0;
            for(int num = 1; num <= 4 && index >= 0; num *= 2)
            {
                if(binaryNumber.charAt(index) == '1')
                    sum += num;
                index--;
            }
            st.push((char)(sum + '0'));
        }

        while(!st.empty())
        {
            bw.write(st.pop());
        }
        
        bw.flush();
        bw.close();
    }
}