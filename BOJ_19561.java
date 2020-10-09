import java.io.*;
import java.util.*;

public class BOJ_19561 {
    private static int N;
    private static int[] mask;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        ArrayList<Node>[] tree = new ArrayList[N + 1];
        for(int index = 0; index < N + 1; index++)
            tree[index] = new ArrayList<Node>();

        StringTokenizer st;
        for(int index = 1; index < N; index++)
        {
            st = new StringTokenizer(br.readLine());

            int startNode = Integer.parseInt(st.nextToken());
            int endNode = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            tree[startNode].add(new Node(endNode, weight));
            tree[endNode].add(new Node(startNode, weight));
        }

        solution(tree);
    }

    private static void solution(ArrayList<Node>[] tree)
    {
        int pointOnCircle = searchPointOnCircle(1, tree, -1);//지름의 1번 점

        int pointOnCircle2 = searchPointOnCircle(pointOnCircle, tree, -1);//지름의 2번 점

        //1번 점과 연결된 두번 째 지름(2번 점 제외)
        int expectPoint1 = searchPointOnCircle(pointOnCircle, tree, pointOnCircle2);
        int expectAnswer1 = mask[expectPoint1];
        
        //2번 점과 연결된 두번 째 지름(1번 점 제외)
        int expectPoint2 = searchPointOnCircle(pointOnCircle2, tree, pointOnCircle);
        int expectAnswer2 = mask[expectPoint2];
        
        
        System.out.println(max(expectAnswer1, expectAnswer2));
        
        return;
    }

    private static int searchPointOnCircle(int startNode, ArrayList<Node>[] tree, int exceptPoint)
    {
        mask = new int[N + 1];
        for(int index = 1; index <= N; index++)
            mask[index] = -1;
        
        mask[startNode] = 0;
        dfs(startNode, tree, exceptPoint);

        int pointOnCircle = 1;
        for(int index = 2; index <= N; index++)
        {
            if(mask[pointOnCircle] < mask[index])
            {
                pointOnCircle = index;
            }
        }

        return pointOnCircle;
    }

    private static void dfs(int nowNodeIndex, ArrayList<Node>[] tree, int exceptPoint)
    {
        for(int index = 0; index < tree[nowNodeIndex].size(); index++)
        {
            Node nextNode = tree[nowNodeIndex].get(index);
            int nextNodeIndex = nextNode.nodeIndex;
            int weight = nextNode.weight;

            if(mask[nextNodeIndex] == -1)
            {
                if(nextNodeIndex == exceptPoint) 
                    continue;
                mask[nextNodeIndex] = mask[nowNodeIndex] + weight;
                dfs(nextNodeIndex, tree, exceptPoint);
            }

        }
    }

    private static int max(int a, int b)
    {
        return a > b ? a : b;
    }

    private static class Node
    {
        public int nodeIndex;
        public int weight;
        
        Node(int nodeIndex, int weight)
        {
            this.nodeIndex = nodeIndex;
            this.weight = weight;
        }
    }
}
