#include <iostream>
#include <queue>

using namespace std;

const int MAX_ISLAND = 7;
const int MAX_NODE = 10;

class DisjointSet
{
private:
    int parent[MAX_NODE];
    int rank[MAX_NODE];
    int find(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        else
        {
            return parent[node] = find(parent[node]);
        }
    }

public:
    DisjointSet()
    {
        for (int index = 0; index < MAX_NODE; index++)
        {
            parent[index] = index;
            rank[index] = 1;
        }
    }

    bool merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
            return false;

        if (rank[u] > rank[v])
        {
            int temp = u;
            u = v;
            v = temp;
        }

        parent[u] = v;

        if (rank[u] == rank[v])
            rank[v]++;

        return true;
    }
};

struct Edges
{
public:
    int start;
    int end;
    int cost;
};
struct Pos
{
public:
    int y;
    int x;
};

int dY[4] = {0, 0, -1, 1};
int dX[4] = {-1, 1, 0, 0};
int map[10][10]; //false

struct ascend
{
    bool operator()(const Edges &left, const Edges &right)
    {
        return left.cost > right.cost ? true : false;
    }
};

void bfs(const int &y, const int &x, const int &N, const int &M, const int &islandNum)
{
    map[y][x] = islandNum;

    queue<Pos> posQueue;
    Pos pos;
    pos.y = y;
    pos.x = x;
    posQueue.push(pos);

    while (!posQueue.empty())
    {
        int m_y = posQueue.front().y;
        int m_x = posQueue.front().x;
        posQueue.pop();

        for (int index = 0; index < 4; index++)
        {
            int newY = m_y + dY[index];
            int newX = m_x + dX[index];
            if (newY >= 0 && newY < N && newX >= 0 && newX < M)
            {
                if (map[newY][newX] < 0)
                {
                    map[newY][newX] = islandNum;
                    Pos m_pos;
                    m_pos.y = newY;
                    m_pos.x = newX;
                    posQueue.push(m_pos);
                }
            }
        }
    }

    return;
}

void getEdgeInfo(const int &N, const int &M, priority_queue<Edges, vector<Edges>, ascend> *edgeQueue)
{

    for (int row = 0; row < N; row++)
    {
        int prevIsland = 0;
        int count = 0;
        for (int col = 0; col < M; col++)
        {
            if (map[row][col] == 0) //바다
            {
                count++;
            }
            else //땅
            {
                if (prevIsland == 0)
                {
                    prevIsland = map[row][col];
                }
                else if(prevIsland != map[row][col])
                {
                    if(count>=2)
                    {
                        Edges m_edge;
                        m_edge.start = prevIsland;
                        m_edge.end = map[row][col];
                        m_edge.cost = count;
                        edgeQueue->push(m_edge);
                    }
                    prevIsland = map[row][col];
                }
                count = 0;
            }
        }
    }
    for (int col = 0; col < M; col++)
    {
        int prevIsland = 0;
        int count = 0;
        for (int row = 0; row < N; row++)
        {
            if (map[row][col] == 0) //바다
            {
                count++;
            }
            else //땅
            {
                if (prevIsland == 0)
                {
                    prevIsland = map[row][col];
                }
                else if(prevIsland != map[row][col])
                {
                    if(count>=2)
                    {
                        Edges m_edge;
                        m_edge.start = prevIsland;
                        m_edge.end = map[row][col];
                        m_edge.cost = count;
                        edgeQueue->push(m_edge);
                    }
                    prevIsland = map[row][col];
                }
                count = 0;
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            cin >> map[row][col];
            if (map[row][col] == 1)
            {
                map[row][col] = -1;
            }
        }
    }

    //connected component with bfs
    int islandCount = 0;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            if (map[row][col] < 0)
            {
                islandCount++;
                bfs(row, col, N, M, islandCount);
            }
        }
    }

    //섬 간의 거리 구하기
    priority_queue<Edges, vector<Edges>, ascend> edgeQueue;
    getEdgeInfo(N, M, &edgeQueue);

    //Minimum spanning tree 구하기
    DisjointSet unionFind;
    int answer = 0;
    int mergeCount = 0;
    while (!edgeQueue.empty())
    {
        int node1 = edgeQueue.top().start;
        int node2 = edgeQueue.top().end;
        int cost = edgeQueue.top().cost;

        if (unionFind.merge(node1, node2))
        {
            answer += cost;
            mergeCount++;
        }

        edgeQueue.pop();
    }

    if (mergeCount != islandCount - 1)
        answer = -1;

    cout << answer;
    return 0;
}