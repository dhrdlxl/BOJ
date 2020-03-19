#include<iostream>
#include<queue>
using namespace std;

bool map[100][100];
int mask[100][100];
int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};

int bfs(int m_y,int m_x,int targetY,int targetX)
{
    queue<pair<int,int>> q;
    q.push(make_pair(m_y,m_x));
    mask[m_y][m_x]=1;

    while(!q.empty())
    {
        
        for(int i=0;i<4;i++)
        {
            int y = q.front().first + Y[i];
            int x = q.front().second + X[i];
            if(y>=0 && x>=0 && y<=targetY && x<=targetX)
            {
                if(map[y][x] && mask[y][x]==0)
                {
                    mask[y][x]=mask[q.front().first][q.front().second]+1;
                    q.push(make_pair(y,x));
                    if(y==targetY && x==targetX)
                    {
                        return mask[y][x];
                    }
                }
            }
        }
        
        q.pop();
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h,w;
    char input;
    cin>>h>>w;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>input;
            if(input=='1')
                map[i][j]=true;
        }
    }

    cout<<bfs(0,0,h-1,w-1);

    return 0;
}