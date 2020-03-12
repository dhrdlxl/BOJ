#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
void dfs(int visit,vector<vector<int>>& vec,vector<int>& mask)
{
    cout<<visit<<' ';
    mask[visit]=1;
    for(int i=0;i<vec[visit].size();i++)
    {
        if(mask[vec[visit][i]]==0)
        {
            dfs(vec[visit][i],vec,mask);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //init
    int N,M,V,x,y;
    cin>>N>>M>>V;
    vector<vector<int>> vec(N+1);
    vector<int> mask(N+1);

    for(int i=0;i<M;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i=0;i<N;i++)
    {
        mask[i+1]=0;
        sort(vec[i+1].begin(),vec[i+1].end());
    }

    
    //dfs_recursive
    dfs(V,vec,mask);
    cout<<'\n';

    //bfs_queue
    for(int i=0;i<N;i++)
    {
        mask[i+1]=0;
    }

    queue<int> q;
    q.push(V);

    mask[V]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        cout<<x<<' ';
        
        for(int i=0;i<vec[x].size();i++)
        {
            if(mask[vec[x][i]]==0)
            {
                q.push(vec[x][i]);
                mask[vec[x][i]]=1;
            }
        }
    }

    return 0;
}