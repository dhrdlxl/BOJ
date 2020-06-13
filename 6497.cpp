#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 200001;

struct Edges
{
public:
    int start;
    int end;
    int cost;
    Edges(){}
    Edges(int m_start, int m_end, int m_cost):start(m_start),
    end(m_end), cost(m_cost){}
};

class DisjointSet
{
private:
    int parent[MAX_SIZE];
    int rank[MAX_SIZE];
public:
    DisjointSet()
    {
        for(int index=0; index<MAX_SIZE; index++)
        {
            parent[index] = index;
            rank[index] = 1;
        }
    }
    
    int Find(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = Find(parent[node]);
    }
    
    bool Union(int u, int v)
    {
        int uRoot = Find(u);
        int vRoot = Find(v);
        if(uRoot == vRoot) return false;
        
        if(rank[uRoot] < rank[vRoot])
        {
            int temp = vRoot;
            vRoot = uRoot;
            uRoot = temp;
        }
        
        parent[vRoot] = uRoot;
        
        if(rank[uRoot] == rank[vRoot])
        {
            rank[uRoot]++;
        }
        return true;
    }
};

bool myComp(Edges a, Edges b)
{
    if(a.cost < b.cost) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n;
    Edges edges[200001];
    
    while(1)
    {
        cin >> m >> n;
        
        if(m+n == 0) break;
        
        int start, end, cost, totalCost = 0;
        for(int index = 0; index < n; index++)
        {
            cin>> start >> end >> cost;
            edges[index] = Edges(start, end, cost);
            totalCost += cost;
        }
    
        sort(edges, edges+n, myComp);
        
        DisjointSet uF;
        int costSum = 0;
        for(int index=0; index < n; index++)
        {
            start = edges[index].start;
            end = edges[index].end;
            cost = edges[index].cost;
            
            if(uF.Union(start, end))
            {
                costSum += cost;
            }
        }
        cout << totalCost - costSum << '\n';
    }
    
    return 0;
}