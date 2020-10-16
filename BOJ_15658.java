import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_15658 {
    private static final int PLUS = 0;
    private static final int MINUS = 1;
    private static final int MULTIPLICATION = 2;
    private static final int DIVISION = 3;

    private static int[] nums;
    private static int[] availableOperator;
    private static int min;
    private static int max;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        nums = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int index = 0; index < N; index++)
        {
            nums[index] = Integer.parseInt(st.nextToken());
        }

        availableOperator = new int[4];
        st= new StringTokenizer(br.readLine());
        for(int index = 0; index < 4; index++)
        {
            availableOperator[index] = Integer.parseInt(st.nextToken());
        }

        min = 1000000001;
        max = -1000000001;
        int[] operators = new int[N - 1];
        recursive(0, operators);

        System.out.println(max);
        System.out.println(min);

        return;
    }

    private static void recursive(int step, int[] operators)
    {
        if(step == operators.length)
        {
            int sum = nums[0];
            for(int index = 1; index < nums.length; index++)
            {
                int operator = operators[index - 1];

                if(operator == PLUS)
                {
                    sum += nums[index];
                }
                else if(operator == MINUS)
                {
                    sum -= nums[index];
                }
                else if(operator == MULTIPLICATION)
                {
                    sum *= nums[index];
                }
                else if(operator == DIVISION)
                {
                    sum /= nums[index];
                }
            }

            if(sum < min)
            {
                min = sum;
            }
            if(sum > max)
            {
                max = sum;
            }

            return;
        }

        for(int operator = 0; operator < 4; operator++)
        {
            if(availableOperator[operator] > 0)
            {
                availableOperator[operator]--;
                operators[step]= operator;

                recursive(step + 1, operators);

                availableOperator[operator]++;
            }
        }
        
        return;
    }
}
