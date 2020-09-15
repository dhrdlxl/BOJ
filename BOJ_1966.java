import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

public class BOJ_1966 {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCase = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for(int tc = 0; tc < testCase; tc++)
        {
            st = new StringTokenizer(br.readLine());
            int docCount = Integer.parseInt(st.nextToken());
            int targetDocIndex = Integer.parseInt(st.nextToken());

            Queue<docInfo> queue = new LinkedList<docInfo>();
            int[] checkPriority = new int[10];

            st = new StringTokenizer(br.readLine());
            for(int index = 0; index < docCount; index++)
            {
                int priority = Integer.parseInt(st.nextToken());
                checkPriority[priority]++;
                if(index == targetDocIndex)
                    queue.offer(new docInfo(priority, true));
                else
                    queue.offer(new docInfo(priority, false));
            }
            
            int answer = 0;
            for(int priority = 9 ; priority > 0;)
            {
                if(checkPriority[priority] == 0)
                {
                    priority--;
                    continue;
                }
                
                while(priority != queue.peek().priority)
                {
                    queue.offer(queue.poll());
                }

                answer++;
                if(queue.peek().target == true)
                    break;
                queue.poll();
                checkPriority[priority]--;
            }
            bw.write(Integer.toString(answer) + "\n");
        }
        
        bw.flush();
        bw.close();
        return;
    } 
    public static class docInfo
    {
        public int priority;
        public boolean target;

        docInfo(int m_priority, boolean m_target)
        {
            priority = m_priority;
            target = m_target;
        }
    }
}

