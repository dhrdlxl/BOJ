#include<iostream>
#include<queue>
using namespace std;

struct node{
    int y;
    int x;
    int block;
    node(int a,int b,int c):y(a),x(b),block(c){}
};
int Y[4]={0,1,0,-1};
int X[4]={1,0,-1,0};
int mask[1000][1000][2];//벽 부수지 않음 / 부숨
int map[1000][1000];
int main(){
    queue<node> q;
    int h,w;
    scanf("%d%d",&h,&w);

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%1d",&map[i][j]);
            mask[i][j][0]=-1;
            mask[i][j][1]=-1;
        }
    }

    mask[0][0][0]=1;
    q.push(node(0,0,0));

    while(!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int block = q.front().block;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int m_y=y+Y[i];
            int m_x=x+X[i];
            if(m_y>=0 && m_x>=0 && m_y<h && m_x<w)
            {
                if(map[m_y][m_x]==0)//길
                {
                    if(mask[m_y][m_x][block]==-1)//처음
                    {
                        mask[m_y][m_x][block] = mask[y][x][block]+1;
                        q.push(node(m_y,m_x,block));
                    }  
                }
                else if(map[m_y][m_x]==1)//벽
                {
                    if(block==0 && mask[m_y][m_x][1]==-1)//벽을 부순적이 없음, 처음
                    {
                        mask[m_y][m_x][1] = mask[y][x][block]+1;
                        q.push(node(m_y,m_x,1));
                    }
                }
            }
        }
    }
    if(mask[h-1][w-1][0]==-1 && mask[h-1][w-1][1]==-1)
        printf("-1");
    else if(mask[h-1][w-1][0]==-1)
        printf("%d",mask[h-1][w-1][1]);
    else if(mask[h-1][w-1][1]==-1)
        printf("%d",mask[h-1][w-1][0]);
    else
        printf("%d",min(mask[h-1][w-1][0],mask[h-1][w-1][1]));
    
    return 0;
}