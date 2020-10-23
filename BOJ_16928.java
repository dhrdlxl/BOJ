import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_16928 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] board = new int[101];
        for(int index = 1; index <= 100; index++)
        {
            board[index] = index;
        }

        for(int index = 0; index < N + M; index++)
        {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            board[from] = to;
        }
        
        int[] mask = new int[101];

        bfs(board, mask);

        System.out.println(mask[100]);
        return;
    }

    private static void bfs(int[] board, int[] mask)
    {
        Queue<Integer> q = new LinkedList<>();
        q.offer(1);

        while(!q.isEmpty())
        {
            int now = q.poll();
            for(int dice = 1; dice <= 6; dice++)
            {
                int nextPos = now + dice;
                if(nextPos > 100)
                    continue;
                
                int next = board[nextPos];
                
                if(mask[next] == 0)
                {
                    mask[next] = mask[now] + 1;
                    q.offer(next);
                }
            }
        }
        return;
    }
}
