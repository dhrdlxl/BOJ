import java.util.*;
import java.io.*;

public class BOJ_12015 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> sequence = new ArrayList<>();
        for(int index = 0; index < N; index++)
        {
            int num = Integer.parseInt(st.nextToken());
            lowerBound(sequence, num);
        }

        System.out.println(sequence.size());
        return;
    }

    private static void lowerBound(ArrayList<Integer> sequence, int num)
    {
        int left = 0;
        int right = sequence.size();

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(sequence.get(mid) < num)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        if(left == sequence.size())
        {
            sequence.add(num);
        }
        else
        {
            sequence.set(left, num);
        }
    }
}