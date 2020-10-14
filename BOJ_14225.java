import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14225 {
    private static boolean[] check;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] S = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        int sum = 0;
        for(int index = 0; index < N; index++)
        {
            S[index] = Integer.parseInt(st.nextToken());
            sum += S[index];
        }

        check = new boolean[sum + 2];

        recursive(0, S, 0);

        for(int index = 1; index <= check.length; index++)
        {
            if(check[index] == false)
            {
                System.out.println(index);
                return;
            }
        }

        return;
    }

    private static void recursive(int step, int[] S, int sum)
    {
        if(step == S.length)
        {
            check[sum] = true;
            return;
        }

        recursive(step + 1, S, sum + S[step] );
        recursive(step + 1, S, sum);
        return;
    }
}