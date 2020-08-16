import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

public class BOJ_1932 {
    public static int max(int a,int b)
    {
        return a >= b ? a : b;
    }
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n][2];
        int nowIndex = 0;
        int beforeIndex = 1;
        for(int height = 0; height < n; height++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            beforeIndex = (nowIndex + 1) % 2;

            for(int node = 0; node <= height; node++)
            {
                int num = Integer.parseInt(st.nextToken());
                int left = 0, right = dp[node][beforeIndex];
                if(node -1 >= 0)
                {
                    left = dp[node -1][beforeIndex];
                }
                
                dp[node][nowIndex] = max(left, right) + num; 
            }
            nowIndex = (nowIndex + 1) % 2;
        }

        int answer = 0;
        nowIndex = (nowIndex + 1) % 2;
        for(int index = 0; index < n; index++)
        {
            if(answer < dp[index][nowIndex])
                answer = dp[index][nowIndex];
        }

        bw.write(Integer.toString(answer));
        bw.flush();
        bw.close();
    }
}