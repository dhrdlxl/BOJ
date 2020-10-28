import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_12886 {
    private static boolean[][] mask = new boolean[1501][1501];

    private static int mid;
    private static boolean answer;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        int sum = A + B + C;
        if(sum % 3 != 0)
        {
            System.out.println(0);
            return;
        }
        mid = sum / 3;

        dfs(A, B, C);
        
        if(answer)
            System.out.println(1);
        else
            System.out.println(0);
        return;
    }

    private static void dfs(int A, int B, int C)
    {
        if(mask[A][B])
        {
            return;
        }
        
        mask[A][B] = true;

        if(A == mid && B == mid && C == mid)
        {
            answer = true;
            return;
        }
        
        int x[] = new int[]{A, B, C};

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(x[i] > x[j])
                {
                    dfs(x[i] - x[j], x[j] + x[j], mid * 3 - (x[i] + x[j]));
                }
            }
        }

        return;
    }
}
