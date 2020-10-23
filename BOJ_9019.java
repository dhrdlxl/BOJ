import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_9019 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int T = Integer.parseInt(br.readLine());

        for(int testCase = 0; testCase < T; testCase++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            System.out.println(bfs(from, to));            
        }

        return;
    }

    private static String bfs(int from, int to)
    {
        Queue<Pos> q = new LinkedList<>();
        boolean[] mask = new boolean[10000];
        mask[from] = true;
        q.offer(new Pos(from, ""));

        String answer = "";
        while(!q.isEmpty())
        {
            int now = q.peek().num;
            String route = q.peek().route;
            q.poll();
            if(now == to)
            {
                answer = route;
                return answer;
            }

            int next = -1;
            if((next = D(mask, now)) >= 0)
            {
                q.offer(new Pos(next, route + "D"));
            }
            if((next = S(mask, now)) >= 0)
            {
                q.offer(new Pos(next, route + "S"));
            }
            if((next = R(mask, now)) >= 0)
            {
                q.offer(new Pos(next, route + "R"));
            }
            if((next = L(mask, now)) >= 0)
            {
                q.offer(new Pos(next, route + "L"));
            }
        }
        return answer;
    }

    private static int D(boolean[] mask, int now)
    {
        int next = (now * 2) % 10000;
        if(mask[next] == false)
        {
            mask[next] = true;
            return next;
        }
        return -1;
    }

    private static int S(boolean[] mask, int now)
    {
        int next = (now - 1 + 10000) % 10000;
        if(mask[next] == false)
        {
            mask[next] = true;
            return next;
        }
        return -1;
    }

    private static int L(boolean[] mask, int now)
    {
        int next = (now * 10 + now / 1000) % 10000;
        if(mask[next] == false)
        {
            mask[next] = true;
            return next;
        }
        return -1;
    }

    private static int R(boolean[] mask, int now)
    {
        int next = (now / 10 + now % 10 * 1000) % 10000;
        if(mask[next] == false)
        {
            mask[next] = true;
            return next;
        }
        return -1;
    }

    private static class Pos
    {
        public int num;
        public String route;
        public Pos(int num, String route)
        {
            this.num = num;
            this.route = route;
        }
    }
}
