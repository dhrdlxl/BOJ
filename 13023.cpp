#include<iostream>
#include<vector>

using namespace std;

bool dfs(int node,int count,vector<vector<int>>& friends,vector<int>& mask)
{
    for(int j=0;j<friends[node].size();j++)
    {
        if(mask[friends[node][j]]==0)
        {
            mask[friends[node][j]]=1;
            count++;
            if(count>=4 || dfs(friends[node][j],count,friends,mask))
            {
                return true;
            }
            mask[friends[node][j]]=0;
            count--;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    int a,b;
    cin>>N>>M;
    vector<vector<int>> friends(N);
    vector<int> mask(N);
    for(int i=0;i<M;i++)
    {
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            mask[j]=0;
        }
        mask[i]=1;
        if(dfs(i,0,friends,mask))
        {
            cout<<1;
            return 0;
        }
    }
    
    cout<<0;
    return 0;
}