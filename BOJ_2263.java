import java.util.*;
import java.io.*;

public class BOJ_2263 {
    private static BufferedWriter bw;
    private static int[] inOrder;
    private static int[] postOrder;
    private static int[] idx;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int nodeCount = Integer.parseInt(br.readLine());
        inOrder = new int[nodeCount];
        postOrder = new int[nodeCount];
        idx = new int[nodeCount + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int index = 0; index < nodeCount; index++) {
            inOrder[index] = Integer.parseInt(st.nextToken());
            idx[inOrder[index]] = index;
        }

        st = new StringTokenizer(br.readLine());
        for (int index = 0; index < nodeCount; index++) {
            postOrder[index] = Integer.parseInt(st.nextToken());
        }

        solution(0, nodeCount - 1, 0, nodeCount - 1);

        bw.flush();
        bw.close();
    }

    private static void solution(int inBegin, int inEnd, int postBegin, int postEnd) throws IOException {
        if (inBegin > inEnd || postBegin > postEnd) {
            return;
        }

        int node = postOrder[postEnd];
        bw.write(Integer.toString(node) + " ");

        solution(inBegin, idx[node] - 1, postBegin, postBegin + (idx[node] - 1 - inBegin));
        solution(idx[node] + 1, inEnd, postBegin + idx[node] - inBegin, postEnd - 1);

        return;
    }

}