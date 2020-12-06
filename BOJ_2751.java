import java.io.*;

public class BOJ_2751 {
    public static int[] sortNum;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        int[] nums = new int[N];
        for(int index = 0; index < N; index++)
        {
            nums[index] = Integer.parseInt(br.readLine());
        }
        
        sortNum = new int[N];
        sort(0, nums.length - 1, nums);

        for(int index = 0; index < N; index++)
            bw.write(nums[index] + "\n");
        
        bw.flush();
        bw.close();
    }   
    
    private static void sort(int begin, int end, int[] nums)
    {
        if(begin == end)
        {
            return;
        }

        int mid = (begin + end) / 2;

        sort(begin, mid, nums);
        sort(mid + 1, end, nums);
        merge(begin, end, nums);

        return;
    }

    private static void merge(int begin, int end, int[] nums)
    {
        int mid = (begin + end) / 2;
        int i = begin;
        int j = mid + 1;
        int k = begin;

        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j])
                sortNum[k++] = nums[i++];
            else
                sortNum[k++] = nums[j++];
        }

        while(i <= mid)
            sortNum[k++] = nums[i++];
        while(j <= end)
            sortNum[k++] = nums[j++];
        
        for(int index = begin; index <= end; index++)
        {
            nums[index] = sortNum[index];
        }
    }
}