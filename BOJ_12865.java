import java.util.*;
import java.io.*;

public class BOJ_12865 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        //init
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[][] items = new int[N + 1][2];
        
        for (int index = 1; index <= N; index++) {
            st = new StringTokenizer(br.readLine());
            items[index][0] = Integer.parseInt(st.nextToken());//W
            items[index][1] = Integer.parseInt(st.nextToken());//V
        }
        
        //solution
        int[][] dp = new int[N + 1][K + 1];
        
        for (int k = 1; k <= K; k++) {
            for (int n = 1; n <= N; n++) {
                int now = dp[n - 1][k];
                int before = 0;
                if (items[n][0] <= k) {
                    now = Math.max(items[n][1], now);
                }
                if (k - items[n][0] >= 1) {
                    before = items[n][1] + dp[n - 1][k - items[n][0]];
                }
                
                dp[n][k] = Math.max(now, before);
            }
        }
        
        System.out.println(dp[N][K]);
    }
}