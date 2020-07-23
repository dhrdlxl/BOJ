//Prim Algorithm
#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

struct Points
{
public:
    int x;
    int y;
    Points() {}
    Points(int m_x, int m_y) : x(m_x), y(m_y) {}
};

struct Edges
{
public:
    int node;
    int cost;
    Edges() {}
    Edges(int m_node, int m_cost) : node(m_node), cost(m_cost) {}
};

int prim(int &N, vector<vector<Edges>> (&edges))
{
    int costSum = 0;
    vector<bool> added(N, false);
    vector<int> minCost(N, INF);

    minCost[0] = 0;
    for (int index = 0; index < N; index++)
    {
        int u = -1;
        for (int v = 0; v < N; v++)
        {
            if (!added[v] && (u == -1 || minCost[u] > minCost[v]))
            {
                u = v;
            }
        }

        if (minCost[u] == INF)
            return -1;

        costSum += minCost[u];
        added[u] = true;

        for (int edgeIndex = 0; edgeIndex < edges[u].size(); edgeIndex++)
        {
            int v = edges[u][edgeIndex].node;
            int cost = edges[u][edgeIndex].cost;

            if(!added[v] && minCost[v] > cost)
            {
                minCost[v] = cost;
            }
        }
    }

    return costSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<Points> points(N);
    vector<vector<Edges>> edges(N);

    int m_x, m_y;
    for (int index = 0; index < N; index++)
    {
        cin >> m_x >> m_y;
        points[index] = Points(m_x, m_y);
    }

    for (int index = 0; index < N - 1; index++)
    {
        for (int nextIndex = index + 1; nextIndex < N; nextIndex++)
        {
            int cost = (points[index].x - points[nextIndex].x) * (points[index].x - points[nextIndex].x) +
                       (points[index].y - points[nextIndex].y) * (points[index].y - points[nextIndex].y);
            if (K <= cost)
            {
                edges[index].push_back(Edges(nextIndex, cost));
                edges[nextIndex].push_back(Edges(index, cost));
            }
        }
    }

    cout << prim(N, edges) << '\n';

    return 0;
}