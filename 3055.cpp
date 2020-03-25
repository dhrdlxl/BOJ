#include<iostream>
#include<queue>
using namespace std;
int Y[4]={0,1,0,-1};
int X[4]={1,0,-1,0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h,w,s_x,s_y;
    char ch;
    char map[50][50];
    int mask[50][50];
    queue<pair<int,int>> q;

    cin>>h>>w;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>map[i][j];
            mask[i][j]=-1;
            if(map[i][j]=='*')//물
            {
                q.push(make_pair(i,j));
            }
            else if(map[i][j]=='S')//고슴도치 위치
            {
                s_y=i;
                s_x=j;
            }
        }
    }
    q.push(make_pair(s_y,s_x));
    mask[s_y][s_x]=0;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int m_y = y+Y[i];
            int m_x = x+X[i];
            if(m_y>=0 && m_x>=0 && m_y<h && m_x<w)
            {
                if(map[y][x]=='*' && mask[m_y][m_x]==-1 && map[m_y][m_x]!='X' && map[m_y][m_x]!='D')//물
                {
                    map[m_y][m_x]='*';
                    mask[m_y][m_x]=-2;
                    q.push(make_pair(m_y,m_x));
                }
                else if(map[y][x]=='S' && mask[m_y][m_x]==-1)
                {
                    if(map[m_y][m_x]=='.')
                    {
                        map[m_y][m_x]='S';
                        mask[m_y][m_x]=mask[y][x]+1;
                        q.push(make_pair(m_y,m_x));
                    }
                    else if(map[m_y][m_x]=='D')
                    {
                        cout<<mask[y][x]+1;
                        return 0;
                    }
                }
            }
            
        }
    }
    cout<<"KAKTUS";
    return 0;
}