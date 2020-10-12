import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2250 {
    private static final int LEVEL = 0;
    private static final int WIDTH = 1;
    private static final int LEFT = 0;
    private static final int RIGHT = 1;
    private static final int MIN = 0;
    private static final int MAX = 1;
    private static final int BLANK = -1;
    private static final int INF = 987654321;

    private static int[][] tree;
    private static int[][] levels;
    private static int visit;
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        tree = new int[N + 1][2];
        levels = new int[N + 1][2];

        StringTokenizer st;
        int findRoot = 0;
        for(int index = 1; index <= N; index++)
        {
            st = new StringTokenizer(br.readLine());
            int root = Integer.parseInt(st.nextToken());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());

            tree[root][LEFT] = left;
            tree[root][RIGHT] = right;

            //levels 초기화
            levels[index][MIN] = INF;
            levels[index][MAX] = 0;

            //root는 한번만 나오는 성질을 이용
            findRoot ^= root;
            if(left > 0)
                findRoot ^= left;
            if(right > 0)
                findRoot ^= right;
        }
        
        visit = 0;
        inOrder(findRoot, 1);
        
        int[] answer = new int[2];
        
        for(int level = 1; level <= N; level++)
        {
            if(levels[level][MIN] == INF || levels[level][MAX] == 0)
                break;
            
            int width = levels[level][MAX] - levels[level][MIN] + 1;
            if(width > answer[WIDTH])
            {
                answer[LEVEL] = level;
                answer[WIDTH] = width;
            }
        }

        System.out.println(Integer.toString(answer[LEVEL]) + " " + Integer.toString(answer[WIDTH]));
    }

    private static void inOrder(int root, int level)
    {
        //left
        if(tree[root][LEFT] != BLANK)
            inOrder(tree[root][LEFT], level + 1);
        
        //root
        visit++;
        if(levels[level][MIN] > visit)
            levels[level][MIN] = visit;
            
        if(levels[level][MAX] < visit)
            levels[level][MAX] = visit;

        //right
        if(tree[root][RIGHT] != BLANK)
            inOrder(tree[root][RIGHT], level + 1);

        return;
    }
}
