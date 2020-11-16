import java.util.*;
import java.io.*;

public class BOJ_1744 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        ArrayList<Integer> positive = new ArrayList<>();
        ArrayList<Integer> negative = new ArrayList<>();

        int answer = 0;
        for(int index = 0; index < N; index++)
        {
            int num = Integer.parseInt(br.readLine());
            if(num <= 0)
            {
                negative.add(num);
            }
            else if(num > 1)
            {
                positive.add(num);
            }
            else if(num == 1)
            {
                answer++;
            }
        }

        negative.sort(Comparator.naturalOrder());
        positive.sort(Comparator.reverseOrder());

        for(int index = 0; index < negative.size();)
        {
            int num1 = negative.get(index);
            index++;
            if(index == negative.size())
            {
                answer += num1;
                break;
            }

            int num2 = negative.get(index);
            index++;

            answer += (num1 * num2);
        }

        for(int index = 0; index < positive.size();)
        {
            int num1 = positive.get(index);
            index++;
            if(index == positive.size())
            {
                answer += num1;
                break;
            }

            int num2 = positive.get(index);
            index++;
            
            answer += (num1 * num2);
        }

        System.out.println(answer);
        return;
    }    
}