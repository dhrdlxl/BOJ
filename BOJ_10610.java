import java.io.*;
import java.util.*;

public class BOJ_10610 {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        String inputNum = sc.nextLine();
        sc.close();

        char[] nums = inputNum.toCharArray();
        Arrays.sort(nums);
        
        int sum = 0;
        for(char num : nums)
        {
            sum += (num - '0');
        }

        if(sum % 3 == 0 && nums[0] == '0')
        {
            StringBuilder sb = new StringBuilder();
            sb.append(nums);
            sb.reverse();
            System.out.println(sb.toString());
        }
        else
            System.out.println(-1);
    }    
}
