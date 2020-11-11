import java.util.*;
import java.io.*;

public class BOJ_14395 {
    private static final int INF = 1000000001;
    private static final String[] operations = new String[]{"*", "+", "-", "/"};
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long s = Long.parseLong(st.nextToken());
        long t = Long.parseLong(st.nextToken());

        HashSet<Long> mask = new HashSet<>();
        Queue<Pos> q = new LinkedList<>();
        q.offer(new Pos(s, ""));
        mask.add(s);
        
        while(!q.isEmpty())
        {
            Pos now = q.poll();
            long nowNum = now.num;
            if(nowNum == t)
            {
                if(now.method == "")
                {
                    System.out.println(0);
                }
                else
                {
                    System.out.println(now.method);
                }
                return;
            } 

            long[] next = new long[]{nowNum * nowNum, nowNum + nowNum, 0, 1};
            if(nowNum == 0)
            {
                next[3] = INF;
            }

            for(int index = 0; index < 4; index++)
            {
                if(next[index] < INF && !mask.contains(next[index]))
                {
                    mask.add(next[index]);
                    q.offer(new Pos(next[index], now.method + operations[index]));
                }
            }
        }
        System.out.println(-1);
    
        return;
    }    

    private static class Pos{
        public long num;
        public String method;
        Pos(long num, String method)
        {
            this.num = num;
            this.method = method;
        }
    }
}
