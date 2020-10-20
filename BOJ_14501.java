import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14501 {
    private static final int TIME = 0;
    private static final int PAY = 1;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[][] days = new int[N + 1][2];
        for(int day = 1; day <= N; day++)
        {
            st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            int pay = Integer.parseInt(st.nextToken());

            days[day][TIME] = time;
            days[day][PAY] = pay;
        }

        int[] dp = new int[N + 1];

        for(int day = 1; day <= N; day++)
        {
            int time = days[day][TIME];
            int pay = days[day][PAY];

            if(day + time - 1 <= N)
            {
                dp[day + time - 1] = max(dp[day + time - 1], dp[day - 1] + pay);
            }
            
            dp[day] = max(dp[day], dp[day - 1]);
        }

        System.out.println(dp[N]);
        return;
    }

    private static int max(int a, int b)
    {
        return a > b ? a : b;
    }
}
