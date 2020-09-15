import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class BOJ_2294 {
    private static int maxNum = 10001;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] coin = new int[n];
        int[] dp = new int[k+1];

        for(int index = 0; index < k + 1; index++)
        {
            dp[index] = maxNum;
        }
        
        for(int index = 0; index < n; index++)
        {
            coin[index] = Integer.parseInt(br.readLine());
            if(coin[index] <= k)
                dp[coin[index]] = 1;
        }
        
        for(int index = 1; index < k + 1; index++)
        {
            int min = dp[index];
            for(int coinIndex = 0; coinIndex < n; coinIndex++)
            {
                int beforeValue = index - coin[coinIndex];
                if(beforeValue > 0 && min > dp[beforeValue] + 1)
                {
                    min = dp[beforeValue] + 1;
                }
            }
            dp[index] = min;
        }
        
        if(dp[k] == maxNum)
            dp[k] = -1;
        
        bw.write(Integer.toString(dp[k]));
        bw.flush();
        bw.close();
    }    
}