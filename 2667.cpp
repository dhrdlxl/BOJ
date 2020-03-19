#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool map[25][25];
int mask[25][25];
int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};

int dfs(int m_y,int m_x,int m_color,int N)
{
    int count=1;
    mask[m_y][m_x]=m_color;
    for(int i=0;i<4;i++)
    {
        int y = m_y+Y[i];
        int x = m_x+X[i];
        if(x>=0 && y>=0 && x<N && y<N && map[y][x] && mask[y][x]==0)
        {
            count+=dfs(y,x,m_color,N);
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    char num;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>num;
            if(num=='1')
                map[i][j]=true;
            else
                map[i][j]=false;
            mask[i][j]=0;
        }
    }

    int color=0;
    int answer[25*25];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j] && mask[i][j]==0)//미확인된 집
            {
                answer[color++]=dfs(i,j,color,N);
            }
        }
    }
    cout<<color<<'\n';
    sort(answer,answer+color);
    for(int i=0;i<color;i++)
    {
        cout<<answer[i]<<'\n';
    }
    return 0;
}