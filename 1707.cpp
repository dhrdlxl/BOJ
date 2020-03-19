#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int>> &vec,vector<int> &mask,int visit,int count)
{   
    mask[visit]=count;
    for(int i=0;i<vec[visit].size();i++)
    {
        if(mask[vec[visit][i]]==0)//아직 방문하지 않은 경우
        {
            if(dfs(vec,mask,vec[visit][i],3-count)==false)
                return false;
        }
        else if(count == mask[vec[visit][i]])//이미 방문, 같은 집합이 인접한 경우
        {
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case,V,E;
    cin>>test_case;

    while(test_case--)
    {
        cin>>V>>E;
        vector<vector<int>> vec(V+1);
        vector<int> mask(V+1);
        int u,v;

        for(int i=0;i<V+1;i++)
            mask[i]=0;

        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        
        bool check=true;
        for(int i=1;i<=V;i++)
        {
            if(mask[i]==0)
            {
                if(dfs(vec,mask,i,1)==false)
                {
                    cout<<"NO"<<'\n';
                    check=false;
                    break;
                }
            }
        }
        if(check)
            cout<<"YES"<<'\n';
    }
    return 0;
}