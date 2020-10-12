import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1991 {
    private static final int BLANK = -1;
    private static final int LEFT = 0;
    private static final int RIGHT = 1;
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[][] tree = new int[N][2];

        StringTokenizer st;
        for(int index = 0; index < N; index++)
        {
            st = new StringTokenizer(br.readLine());
            int root = st.nextToken().toCharArray()[0] - 'A';
            int left = st.nextToken().toCharArray()[0] - 'A';
            int right = st.nextToken().toCharArray()[0] - 'A';

            if(left == '.' - 'A')
            {
                left = BLANK;
            }
            if(right == '.' - 'A')
            {
                right = BLANK;
            }
            
            tree[root][LEFT] = left;
            tree[root][RIGHT] = right;
        }

        preOrder(tree, 0);
        System.out.print("\n");

        inOrder(tree, 0);
        System.out.print("\n");

        postOrder(tree, 0);

        return;
    }

    private static void preOrder(int[][] tree, int root)
    {
        System.out.print((char)(root + 'A'));

        if(tree[root][LEFT] != BLANK)
            preOrder(tree, tree[root][LEFT]);

        if(tree[root][RIGHT] != BLANK)
            preOrder(tree, tree[root][RIGHT]);

        return;
    }

    private static void inOrder(int[][] tree, int root)
    {
        if(tree[root][LEFT] != BLANK)
            inOrder(tree, tree[root][LEFT]);

        System.out.print((char)(root + 'A'));

        if(tree[root][RIGHT] != BLANK)
            inOrder(tree, tree[root][RIGHT]);

        return;
    }

    private static void postOrder(int[][] tree, int root)
    {
        if(tree[root][LEFT] != BLANK)
            postOrder(tree, tree[root][LEFT]);
   
        if(tree[root][RIGHT] != BLANK)
            postOrder(tree, tree[root][RIGHT]);
            
        System.out.print((char)(root + 'A'));

        return;
    }
}
