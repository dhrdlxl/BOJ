import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class BOJ_1309 {
    static final int div = 9901;
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[][] dp = new int[N][3];
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        for(int index = 1; index < N; index++)
        {
            dp[index][0] = (dp[index-1][0] + dp[index-1][1] + dp[index-1][2]) % div;
            dp[index][1] = (dp[index-1][0] + dp[index-1][2]) % div;
            dp[index][2] = (dp[index-1][0] + dp[index-1][1]) % div;
        }
        bw.write(Integer.toString((dp[N-1][0] + dp[N-1][1] + dp[N-1][2]) % div));
        bw.flush();
        bw.close();
    }    
}