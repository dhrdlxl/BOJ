import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_11725 {
    private static int[] parents;
    private static ArrayList<Integer>[] graph;
    private static boolean[] mask;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        graph = new ArrayList[N + 1];
        mask = new boolean[N + 1];
        for(int index = 1; index <= N; index++)
        {
            graph[index] = new ArrayList<Integer>();
        }

        StringTokenizer st;
        for(int index = 1; index < N; index++)
        {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            graph[from].add(to);
            graph[to].add(from);
        }

        parents = new int[N + 1];
        dfs(1);

        for(int node = 2; node <= N; node++)
        {
            bw.write(Integer.toString(parents[node]) + "\n");
        }
        bw.flush();
        bw.close();
        return;
    }

    private static void dfs(int node)
    {
        for(int index = 0; index < graph[node].size(); index++)
        {
            int nextNode = graph[node].get(index);
            if(mask[nextNode] == false)
            {
                mask[nextNode] = true;
                parents[nextNode] = node;
                dfs(nextNode);
            }
        }

        return;
    }
}
