#include<iostream>
using namespace std;
int board[20][20];
int R,C;
bool mask['Z'-'A'+1];
int goX[4]={1,0,-1,0};
int goY[4]={0,1,0,-1};
int max(int a,int b)
{
    return a>b? a:b;
}
int go(int y,int x)
{
    int answer=0;
    mask[board[y][x]]=true;
    for(int i=0;i<4;i++)
    {
        int m_y=y+goY[i];
        int m_x=x+goX[i];
        if(m_y>=0 && m_x>=0 && m_y<R && m_x<C)
        {
            if(!mask[board[m_y][m_x]])
            {
                answer=max(answer,go(m_y,m_x));
                mask[board[m_y][m_x]]=false;
            }
        }
    }

    return answer+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin>>R>>C;
    char alpha;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>alpha;
            board[i][j]=alpha-'A';
        }
    }

    cout<<go(0,0);
    return 0;
}