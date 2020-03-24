#include<iostream>
#include<deque>
using namespace std;

int Y[4]={0,1,0,-1};
int X[4]={1,0,-1,0};

int main(){
    int h,w,num;
    int map[100][100];
    int mask[100][100];

    deque<pair<int,int>> dq;
    scanf("%d%d",&w,&h);
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%1d",&map[i][j]);
            mask[i][j]=-1;
        }
    }

    dq.push_front(make_pair(0,0));
    mask[0][0]=0;
    while(!dq.empty())
    {
        int y=dq.front().first;
        int x=dq.front().second;
        dq.pop_front();

        for(int i=0;i<4;i++)
        {
            int m_y = y+Y[i];
            int m_x = x+X[i];
            if(m_y>=0 && m_x>=0 && m_y<h && m_x<w)
            {
                if(mask[m_y][m_x]==-1)
                {
                    if(map[m_y][m_x]==0)//±æ
                    {
                        mask[m_y][m_x]=mask[y][x];
                        dq.push_front(make_pair(m_y,m_x));
                    }
                    else if(map[m_y][m_x]==1)//º®
                    {
                        mask[m_y][m_x]=mask[y][x]+1;
                        dq.push_back(make_pair(m_y,m_x));
                    }
                    
                }
            }
        }
    }

    printf("%d",mask[h-1][w-1]);
    return 0;
}