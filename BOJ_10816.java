import java.io.*;
import java.util.*;

public class BOJ_10816 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] cards = new int[N];
        for(int index = 0; index < N; index++)
        {
            cards[index] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(cards);

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int index = 0; index < M; index++)
        {
            int num = Integer.parseInt(st.nextToken());
            int lowerBound = LowerBound(num, cards);
            int upperBound = UpperBound(num, cards);
            
            bw.write((upperBound - lowerBound) + " ");
        }
        br.close();
        bw.flush();
        bw.close();
        
    }
    private static int LowerBound(int num, int[] cards)
    {
        int begin = 0;
        int end = cards.length - 1;
        int result = -1;

        while(begin <= end)
        {
            int mid = (begin + end) / 2;

            if(cards[mid] >= num)
            {
                result = mid;
                end = mid - 1;
            }
            else if(cards[mid] < num)
            {
                result = mid + 1;
                begin = mid + 1;
            }
        }
        return result;
    }

    private static int UpperBound(int num ,int[] cards)
    {
        int begin = 0;
        int end = cards.length - 1;
        int result = -1;

        while(begin <= end)
        {
            int mid = (begin + end) / 2;

            if(cards[mid] <= num)
            {
                result = mid + 1;
                begin = mid + 1;
            }
            else if(cards[mid] > num)
            {
                result = mid;
                end = mid - 1;
            }
        }

        return result;
    }
}