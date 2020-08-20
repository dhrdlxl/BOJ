import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class BOJ_2133 {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        long[] dp = new long[31];

        dp[0] = 1;
        for(int i = 2; i <= N; i+=2)
        {
            dp[i] = dp[i - 2] * 3;
            for(int j = i - 4; j >= 0; j-=2)
            {
                dp[i] += dp[j] * 2;
            }
        }
        bw.write(Long.toString(dp[N]));

        bw.flush();
        bw.close();
    }
}