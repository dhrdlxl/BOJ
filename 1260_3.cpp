#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

struct edge{
    int begin;
    int end;
};

bool compare(edge a,edge b)
{
    if(a.begin==b.begin)
        return a.end<b.end;
    else
        return a.begin<b.begin;
}
void dfs_stack(edge* edges,int* node,int V,int* mask)
{
    stack<pair<int,int>> st;//node, index
    st.push(make_pair(V,0));
    mask[V]=1;
    cout<<V<<' ';
    while(!st.empty())
    {
        int visit = st.top().first;
        int index = st.top().second;
        st.pop();
        
        for(int i=index+node[visit-1];i<node[visit];i++)
        {
            if(mask[edges[i].end]==0)
            {
                mask[edges[i].end]=1;
                cout<<edges[i].end<<' ';
                st.push(make_pair(visit,i+1-node[visit-1]));
                st.push(make_pair(edges[i].end,0));
                break;
            }
        }
    }
    return;
}

void dfs_recursive(edge* edges,int* node,int V,int* mask)
{
    mask[V]=1;
    cout<<V<<' ';
    for(int i=node[V-1];i<node[V];i++)
    {
        if(mask[edges[i].end]==0)
        {
            dfs_recursive(edges,node,edges[i].end,mask);
        }
    }
    return;
}

void bfs(edge* edges,int* node,int V,int* mask)
{
    queue<int> q;
    q.push(V);
    mask[V]=1;
    cout<<V<<' ';
    while(!q.empty())
    {
        int visit = q.front();
        q.pop();
        for(int i=node[visit-1];i<node[visit];i++)
        {
            if(mask[edges[i].end]==0)
            {
                cout<<edges[i].end<<' ';
                mask[edges[i].end]=1;
                q.push(edges[i].end);
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,V,a,b;
    cin>>N>>M>>V;

    edge* edges=new edge[2*M];
    int* node =new int[N+1];
    int* mask = new int[N+1];
    for(int i=0;i<N+1;i++)
    {
        node[i]=0;
        mask[i]=0;
    }
        

    for(int i=0;i<2*M;i++)
    {
        cin>>a>>b;
        edges[i].begin=a;
        edges[i].end=b;
        i++;
        edges[i].begin=b;
        edges[i].end=a;
    }

    sort(edges,edges+2*M,compare);
    for(int i=0;i<2*M;i++)
    {
        node[edges[i].begin]++;
    }
    for(int i=0;i<N;i++)
    {
        node[i+1]+=node[i];
    }
    
    dfs_recursive(edges,node,V,mask);
    cout<<'\n';

    for(int i=0;i<N+1;i++)
    {
        mask[i]=0;
    }
    bfs(edges,node,V,mask);

    delete[] edges;
    delete[] node;
    delete[] mask;
    return 0;
}