import java.util.*;
import java.io.*;

public class BOJ_2109 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        TreeMap<Integer, ArrayList<Integer>> schedules = new TreeMap<>();
        int maxDay = 0;
        for(int index = 0; index < N; index++)
        {
            st = new StringTokenizer(br.readLine());
            int pay = Integer.parseInt(st.nextToken());
            int day = Integer.parseInt(st.nextToken());
            if(!schedules.containsKey(day))
            {
                schedules.put(day, new ArrayList<Integer>());
            }
            schedules.get(day).add(pay);

            if(maxDay < day)
                maxDay = day;
        }
        
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int day = maxDay; day > 0; day--)
        {
            if(schedules.containsKey(day))
            {
                for(int pay : schedules.get(day))
                {
                    pq.offer(pay);
                }
            }
            if(!pq.isEmpty())
            {
                answer += pq.poll();
            }
        }

        System.out.println(answer);
        return;
    }
}