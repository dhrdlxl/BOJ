import java.util.*;
import java.io.*;

public class BOJ_10815 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> cards = new ArrayList<>();
        while(st.hasMoreTokens())
        {
            cards.add(Integer.parseInt(st.nextToken()));
        }

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        ArrayList<Integer> nums = new ArrayList<>();
        while(st.hasMoreTokens())
        {
            nums.add(Integer.parseInt(st.nextToken()));
        }

        cards.sort(Comparator.naturalOrder());

        for(int num : nums)
        {
            if(binarySearch(num, cards))
            {
                System.out.print(1 + " ");
            }
            else
            {
                System.out.print(0 + " ");
            }
        }

    }

    private static boolean binarySearch(int num, ArrayList<Integer> cards)
    {
        int begin = 0;
        int end = cards.size() - 1;

        while(begin <= end)
        {
            int mid = (begin + end) / 2;

            if(cards.get(mid) < num)
            {
                begin = mid + 1;
            }
            else if(cards.get(mid) > num)
            {
                end = mid - 1;
            }
            else if(cards.get(mid) == num)
            {
                return true;
            }
        }
        return false;
    }
}