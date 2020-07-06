#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 2001;

struct Edges
{
public:
    int x;
    int y;
    Edges() {}
    Edges(int m_x, int m_y) : x(m_x), y(m_y) {}
};

struct Costs
{
public:
    int cost;
    int from;
    int to;
    Costs() {}
    Costs(int m_cost, int m_from, int m_to) : cost(m_cost), from(m_from), to(m_to) {}
};

class DisjointSet
{
private:
    int parents[MAX_SIZE];
    int rank[MAX_SIZE];

public:
    DisjointSet()
    {
        for (int index = 0; index < MAX_SIZE; index++)
        {
            parents[index] = index;
            rank[index] = 1;
        }
    }

    int Find(int u)
    {
        if (parents[u] == u)
            return u;
        return parents[u] = Find(parents[u]);
    }

    bool Merge(int u, int v)
    {
        int uParent, vParent;
        uParent = Find(u);
        vParent = Find(v);

        if (uParent == vParent)
            return false;

        if (rank[uParent] < rank[vParent])
        {
            int temp = uParent;
            uParent = vParent;
            vParent = temp;
        }

        parents[vParent] = uParent;

        if (rank[uParent] == rank[vParent])
        {
            rank[uParent]++;
        }
        return true;
    }
};

bool myComp(Costs &a, Costs &b)
{
    if (a.cost < b.cost)
        return true;
    return false;
}

Costs costs[1999001];
int countCosts;

int MST(int &N, int &K)
{
    int answer = 0;
    int mergeCount = 0;

    DisjointSet uf;

    int cost, from ,to;
    for (int index = 0; index < countCosts; index++)
    {
        cost = costs[index].cost;
        from = costs[index].from;
        to = costs[index].to;
        if (cost < K)
            continue;

        if(uf.Merge(from, to))
        {
            answer += cost;
            mergeCount++;
        }
    }

    if(mergeCount != N-1)
        answer = -1;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;

    cin >> N >> K;

    int x, y;
    Edges edges[MAX_SIZE];
    for (int index = 1; index <= N; index++)
    {
        cin >> x >> y;
        edges[index] = Edges(x, y);
    }

    for (int index = 1; index < N; index++)
    {
        for (int nextIndex = index + 1; nextIndex <= N; nextIndex++)
        {
            int cost = (edges[index].x - edges[nextIndex].x) * (edges[index].x - edges[nextIndex].x) + (edges[index].y - edges[nextIndex].y) * (edges[index].y - edges[nextIndex].y);

            costs[countCosts] = Costs(cost, index, nextIndex);
            countCosts++;
        }
    }

    sort(costs, costs + countCosts, myComp);

    cout << MST(N, K) << '\n';

    return 0;
}