#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int NODE_MAX = 200001;

struct Edges
{
public:
    int from;
    int to;
    Edges() {}
    Edges(int m_from, int m_to) : from(m_from), to(m_to) {}
};

class DisjointSet
{
private:
    int parents[NODE_MAX];
    int rank[NODE_MAX];

public:
    DisjointSet()
    {
        for (int index = 0; index < NODE_MAX; index++)
        {
            parents[index] = index;
            rank[index] = 1;
        }
    }

    int Find(int node)
    {
        if (node == parents[node])
            return node;
        return Find(parents[node]);
    }
    bool Union(int u, int v)
    {
        int uRoot, vRoot;
        uRoot = Find(u);
        vRoot = Find(v);

        if (uRoot == vRoot)
            return false;

        if (rank[vRoot] > rank[uRoot])
        {
            int temp = vRoot;
            vRoot = uRoot;
            uRoot = temp;
        }

        parents[vRoot] = uRoot;

        if (rank[uRoot] == rank[vRoot])
            rank[uRoot]++;

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> parent(N + 1);
    int parentNode;
    for (int index = 2; index <= N; index++)
    {
        cin >> parentNode;
        parent[index] = parentNode;
    }

    vector<bool> checkDelete(N + 1, false);
    stack<Edges> querys;
    int status, from, to, deleteNode;
    for (int index = 0; index < N - 1 + Q; index++)
    {
        cin >> status;
        if (status == 1)
        {
            cin >> from >> to;
            querys.push(Edges(from, to));
        }
        else if (status == 0)
        {
            cin >> deleteNode;
            querys.push(Edges(-1, deleteNode));
            checkDelete[deleteNode] = true;
        }
    }

    DisjointSet uf;
    for (int index = 2; index <= N; index++)
    {
        if (checkDelete[index] != true)
        {
            uf.Union(parent[index], index);
        }
    }

    stack<bool> answer;
    while (!querys.empty())
    {
        int m_from = querys.top().from;
        int m_to = querys.top().to;
        querys.pop();

        if (m_from == -1) //delete -> Union
        {
            uf.Union(parent[m_to], m_to);
        }
        else //query
        {
            if (uf.Find(m_from) == uf.Find(m_to))
                answer.push(true);
            else
                answer.push(false);
        }
    }

    while (!answer.empty())
    {
        if (answer.top() == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        answer.pop();
    }

    return 0;
}