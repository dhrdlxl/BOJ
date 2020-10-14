import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_14888 {
    private static final int PLUS = 0;
    private static final int MINUS = 1;
    private static final int MULTIPLICATION = 2;
    private static final int DIVISION = 3;

    private static int min;
    private static int max;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] nums = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());;
        for(int index = 0 ; index < N; index++)
        {
            nums[index] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        ArrayList<Integer> operators = new ArrayList<>();
        
        for(int operator = 0; operator < 4; operator++)
        {
            int operatorCount = Integer.parseInt(st.nextToken());
            while(operatorCount > 0)
            {
                operatorCount--;
                operators.add(operator);
            }
        }

        min = 1000000001;
        max = -1000000001;
        do{
            calc(operators, nums);
        }while(next_permutation(operators));
        
        System.out.println(max);
        System.out.println(min);
        return;
    }

    private static void calc(ArrayList<Integer> operators, int[] nums)
    {
        int result = nums[0];
        for(int index = 1; index < nums.length; index++)
        {
            if(operators.get(index - 1) == PLUS)
            {
                result += nums[index];
            }
            else if(operators.get(index - 1) == MINUS)
            {
                result -= nums[index];
            }
            else if(operators.get(index - 1) == MULTIPLICATION)
            {
                result *= nums[index];
            }
            else if(operators.get(index - 1) == DIVISION)
            {
                result /= nums[index];
            }
        }
        
        if(result > max)
            max = result;
        if(result < min)
            min = result;
        
        return;
    }

    private static boolean next_permutation(ArrayList<Integer> operators)
    {
        int i = operators.size() - 1;
        while(i > 0 && operators.get(i - 1) >= operators.get(i))
        {
            i--;
        }
        
        if(i <= 0)
            return false;
        
        int j = operators.size() - 1;
        while(j >= 0 && operators.get(i - 1) >= operators.get(j))
        {
            j--;
        }
        swap(operators, i - 1, j);

        j = operators.size() - 1;
        while(i < j)
        {
            swap(operators, i, j);
            i++;
            j--;
        }
        return true;
    }

    private static void swap(ArrayList<Integer> operators, int i, int j)
    {
        int temp = operators.get(i);
        operators.set(i, operators.get(j));
        operators.set(j, temp);
    }
}
