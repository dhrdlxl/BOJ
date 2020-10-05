import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements Comparable<Node> {
    public int v;
    public int w;

    public Node(int v, int w) {
        this.v = v;
        this.w = w;
    }

    @Override
    public int compareTo(Node node) {
        return this.w - node.w;
    }
}

public class BOJ_1753 {
    private static final int INF = 200001;
    private static ArrayList<Node>[] tree;
    private static int distance[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int startNode = Integer.parseInt(br.readLine());

        tree = new ArrayList[V + 1];
        distance = new int[V + 1];

        for (int node = 1; node <= V; node++) {
            tree[node] = new ArrayList<Node>();
            distance[node] = INF;
        }

        for (int index = 0; index < E; index++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            tree[u].add(new Node(v, w));
        }

        Dijkstra(startNode);

        for (int node = 1; node <= V; node++) {
            if (distance[node] == INF)
                bw.write("INF\n");
            else
                bw.write(Integer.toString(distance[node]) + "\n");
        }
        bw.flush();
        bw.close();
        return;
    }

    private static void Dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        distance[start] = 0;

        while (!pq.isEmpty()) {
            int here = pq.peek().v;
            int w = pq.peek().w;

            if (w <= distance[here]) {
                for (Node node : tree[here]) {
                    if (w + node.w < distance[node.v]) {
                        distance[node.v] = w + node.w;
                        pq.offer(new Node(node.v, w + node.w));
                    }
                }
            }

            pq.poll();
        }
    }
}