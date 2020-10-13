import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_1339 {
    private static final int MAXNUM = 9;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] alphabetIndexTable = new int['Z' - 'A' + 1];
        Arrays.fill(alphabetIndexTable, -1);
        
        int alphabetCount = 0;
        String[] words = new String[N];
        for(int index = 0; index < N; index++)
        {
            words[index] = br.readLine();
            for(int alphabetIndex = 0; alphabetIndex < words[index].length(); alphabetIndex++)
            {
                char alphabet = words[index].charAt(alphabetIndex);
                if(alphabetIndexTable[alphabet - 'A'] == -1)
                {
                    alphabetIndexTable[alphabet - 'A'] = alphabetCount;
                    alphabetCount++;
                }
            }
        }

        int[] nums = new int[alphabetCount];
        for(int index = 0; index < alphabetCount; index++)
        {
            nums[index] = MAXNUM - index;
        }

        int answer = 0;
        do{
            int sum = 0;
            for(String word : words)
            {
                int num = 0;
                for(int index = 0; index < word.length() ;index++)
                {
                    char alphabet = word.charAt(index);
                    num *= 10;
                    num += nums[alphabetIndexTable[alphabet - 'A']];
                }
                sum += num;
            }
            if(sum > answer)
                answer = sum;
        }while(prev_permutation(nums));

        System.out.println(answer);
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
        while(nums[i - 1] <= nums[j])
        {
            j--;
        }
        swap(nums, i - 1, j);

        j = nums.length - 1;
        while(i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
        return true;
    }

    private static void swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
