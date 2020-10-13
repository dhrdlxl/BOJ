import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ_2529{
    private static final int MAX = 9;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());

        char[] relation = new char[K + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int index = 1; index <= K; index++)
        {
            relation[index] = st.nextToken().charAt(0);
        }

        int[] min = new int[K + 1];
        int[] max = new int[K + 1];

        for(int index = 0; index <= K; index++)
        {
            min[index] = index;
            max[index] = MAX - index;
        }

        do{
            if(check(relation, min))
                break;
        }while(next_permutation(min));

        do{
            if(check(relation, max))
                break;
        }while(prev_permutation(max));

        for(int index = 0; index <=K; index++)
            bw.write(Integer.toString(max[index]));
        
        bw.write("\n");
        
        for(int index = 0; index <=K; index++)
            bw.write(Integer.toString(min[index]));
        
        bw.flush();
        bw.close();
        return;
    }

    private static boolean check(char[] relation, int[] nums)
    {
        int left = nums[0];
        int right;
        for(int index = 1; index < nums.length; index++)
        {
            right = nums[index];

            if(relation[index] == '>' && left < right)
                return false;
            if(relation[index] == '<' && left > right)
                return false;

            left = right;
        }
        return true;
    }

    private static boolean prev_permutation(int[] nums)
    {
        int i = nums.length - 1;
        while(i > 0 && nums[i - 1] <= nums[i])
        {
            i--;
        }
        if(i <= 0)
            return false;

        int j = nums.length - 1;
        while(j >= 0 && nums[i - 1] <= nums[j])
        {
            j--;
        }
        
        swap(nums ,i - 1, j);

        j = nums.length - 1;
        while(i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }

        return true;
    }

    private static boolean next_permutation(int[] nums)
    {
        int i = nums.length - 1;
        while(i > 0 && nums[i - 1] >= nums[i])
        {
            i--;
        }
        if(i <= 0)
            return false;
        
        int j = nums.length - 1;
        while(j >= 0 && nums[i - 1] >= nums[j])
        {
            j--;
        }

        swap(nums, i - 1, j);
            
        j = nums.length - 1;
        while(i < j)
        {
            swap(nums, i , j);
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