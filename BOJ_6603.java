import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ_6603 {
    private static final int END = 6;

    private static BufferedWriter bw;
    private static int[] S;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String line;
        StringTokenizer st;
        while ((line = br.readLine()).charAt(0) != '0') {
            st = new StringTokenizer(line);
            int k = Integer.parseInt(st.nextToken());

            S = new int[k];
            for (int index = 0; index < k; index++) {
                S[index] = Integer.parseInt(st.nextToken());
            }

            recursive(0, 0, 0);

            bw.write("\n");
        }

        bw.flush();
        bw.close();
        return;
    }

    private static void recursive(int step, int start, int bitMask) throws IOException
    {
        if(step == END)
        {
            for(int index = 0; index < S.length; index++)
            {
                if((bitMask & (1 << index)) > 0)
                {
                    bw.write(Integer.toString(S[index]) + " ");
                }
            }
            bw.write("\n");
            return;
        }
        
        if(start == S.length)
            return;

        recursive(step + 1, start + 1, bitMask | (1 << start) );
        recursive(step, start + 1, bitMask);
        
        return;
    }
}
