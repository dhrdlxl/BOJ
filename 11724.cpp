#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;
struct Edge{
    int u;
    int v;
};
int cnt[1001];
bool mask[1001];
//
bool cmp(Edge a,Edge b){
    if(a.u==b.u)
        return a.v<b.v;
    else
        return a.u<b.u;
}

void dfs(Edge* edge, int visit)
{
    stack<pair<int,int>> st;
    st.push(make_pair(visit,cnt[visit-1]));

    while(!st.empty())
    {
        int V = st.top().first;
        int index = st.top().second;
        st.pop();
        for(int i=index;i<cnt[V];i++)
        {
            if(mask[edge[i].v]==false)
            {
                mask[edge[i].v]=true;
                st.push(make_pair(V,i));
                st.push(make_pair(edge[i].v,cnt[edge[i].v-1]));
            }
        }
    }
}

void solve(Edge* edge,int N)
{
    int answer=0;
    for(int i=1;i<=N;i++)//i == node number
    {
        if(mask[i]==false)
        {
            answer++;
            mask[i]=true;
            dfs(edge,i);
        }
    }
    cout<<answer;
}

//
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,a,b;
    cin>>N>>M;
    Edge *edge = new Edge[M*2];
    for(int i=0;i<M;i++)
    {
        cin>>a>>b;
        edge[i].u=a;
        edge[i].v=b;
        edge[i+M].u=b;
        edge[i+M].v=a;
    }

    sort(edge,edge+2*M,cmp);
    
    for(int i=0;i<2*M;i++)
    {
        cnt[edge[i].u]++;
    }
    for(int i=0;i<N;i++)
    {
        cnt[i+1]+=cnt[i];
    }

    //
    solve(edge,N);
    
    delete[] edge;
    return 0;
}