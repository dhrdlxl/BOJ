import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_16198 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] balls = new int[N];
        for(int index = 0; index < N; index++)
        {
            balls[index] = Integer.parseInt(st.nextToken());
        }

        int[] order = new int[N - 2];
        for(int index = 1; index < N - 1; index++)
        {
            order[index - 1] = index;
        }

        int answer = 0;
        boolean[] mask = new boolean[N];
        do{
            int sum = 0;
            Arrays.fill(mask, false);

            for(int index = 0; index < order.length; index++)
            {
                int x = order[index];
                int left = x - 1;
                int right = x + 1;
                mask[x] = true;

                while(mask[left] == true)
                {
                    left--;
                }
                while(mask[right] == true)
                {
                    right++;
                }

                sum += balls[left] * balls[right];
            }
            if(sum > answer)
            {
                answer = sum;
            }
        }while(next_permutation(order));

        System.out.println(answer);
        return;
    }

    private static boolean next_permutation(int[] order)
    {
        int i = order.length - 1;
        while(i > 0 && order[i - 1] >= order[i])
        {
            i--;
        }
        if(i <= 0)
            return false;

        int j = order.length - 1;
        while(order[i - 1] >= order[j])
        {
            j--;
        }

        swap(order, i - 1, j);

        j = order.length - 1;
        while(i < j)
        {
            swap(order, i, j);
            i++;
            j--;
        }
        return true;
    }

    private static void swap(int[] arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        return;
    }
}
