import java.io.*;

public class BOJ_20164 {
    private static int min = 1000000000;
    private static int max = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String number = br.readLine();
        
        simulation(number, 0);

        System.out.println(min + " " + max);
    }

    private static void simulation(String number, int count)
    {
        if(number.length() == 1)
        {
            if(Integer.parseInt(number) % 2 == 1)
                count++;
            
            if(min > count)
                min = count;
            if(max < count)
                max = count;

            return;
        }
        else if(number.length() == 2)
        {
            int left = number.charAt(0) - '0';
            int right = number.charAt(1) - '0';
            if(left % 2 == 1)
                count++;
            if(right % 2 == 1)
                count++;
            
            simulation(Integer.toString(left + right), count);
        }
        else
        {
            for(int index = 0; index < number.length(); index++)
            {
                if((number.charAt(index) - '0') % 2 == 1)
                    count++;
            }

            //3가지로 나누는 방법 구하기
            int[] permutation = new int[number.length() - 1];
            for(int index = number.length() - 2; index >= number.length() - 3; index--)
            {
                permutation[index] = 1;
            }

            do{
                int[] divideNum = new int[3];
                int divide = 0, start = 0;
                for(int index = 0; index < permutation.length; index++)
                {
                    if(permutation[index] == 1)
                    {
                        divideNum[divide] = Integer.parseInt(number.substring(start, index + 1));
                        divide++;
                        start = index + 1;
                    }
                }
                divideNum[divide] = Integer.parseInt(number.substring(start, number.length()));

                simulation(Integer.toString(divideNum[0] + divideNum[1] + divideNum[2]), count);

            }while(next_permutation(permutation));
        }
        return;
    }

    private static boolean next_permutation(int[] permutation)
    {
        int i = permutation.length - 1;
        while(i > 0 && permutation[i] <= permutation[i - 1])
        {
            i--;
        }
        if(i <= 0)
            return false;
        
        int j = permutation.length - 1;
        while(permutation[j] <= permutation[i - 1])
        {
            j--;
        }
        swap(permutation, i - 1, j);

        j = permutation.length - 1;
        while(i < j)
        {
            swap(permutation, i, j);
            i++;
            j--;
        }
        return true;
    }
    private static void swap(int[] permutation, int i, int j)
    {
        int temp = permutation[i];
        permutation[i] = permutation[j];
        permutation[j] = temp;
        return;
    }
}