#include<iostream>
#include<queue>
using namespace std;

bool map[50][50];
bool mask[50][50];
int Y[8]={-1,-1,-1,0,0,1,1,1};
int X[8]={-1,0,1,-1,1,-1,0,1};

void bfs(int m_y,int m_x,int m_h,int m_w)
{
    queue<pair<int,int>> q;
    q.push(make_pair(m_y,m_x));
    mask[m_y][m_x]=true;

    while(!q.empty())
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                int y = q.front().first+Y[i];
                int x = q.front().second+X[i];
                if(y>=0 && x>=0 && y<m_h && x<m_w)
                {
                    if(map[y][x] && mask[y][x]==false)
                    {
                        mask[y][x]=true;
                        q.push(make_pair(y,x));
                    }
                }
            }
        }
        q.pop();
    }

    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w,h;
    while(cin>>w>>h)
    {
        if(w+h==0)break;

        int input;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>input;
                map[i][j]=input;
                mask[i][j]=false;
            }
        }
        int answer=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(map[i][j] && mask[i][j]==false)
                {
                    answer++;
                    bfs(i,j,h,w);
                }
            }
        }
        cout<<answer<<'\n';
    }
    return 0;
}