#include<iostream>
#include<queue>
using namespace std;

int board[9][9];
int block[3][3];
int col[9];
int row[9];

bool find(int y,int x)
{
    if(y==9)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<board[i][j]<<' ';
            }
            cout<<'\n';
        }
        return true;
    }
    if(board[y][x]!=0)
    {
        int m_y=y;
        int m_x=x;
        if(m_x+1==9)
        {
            m_y++;
            m_x=0;
        }
        else
            m_x++;
        
        return find(m_y,m_x);
    }
    

    for(int i=1;i<=9;i++)
    {
        if(((block[y/3][x/3]&(1<<i))==0) && ((col[x]&(1<<i))==0) && ((row[y]&(1<<i))==0))
        {
            block[y/3][x/3]|=(1<<i);
            col[x]|=(1<<i);
            row[y]|=(1<<i);
            board[y][x]=i;
            int m_y=y;
            int m_x=x;
            if(m_x+1==9)
            {
                m_y++;
                m_x=0;
            }
            else
                m_x++;
            
            if(find(m_y,m_x))
                return true;
            
            block[y/3][x/3]^=(1<<i);
            col[x]^=(1<<i);
            row[y]^=(1<<i);
            board[y][x]=0;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>num;
            board[i][j]=num;
            if(num!=0)
            {
                block[i/3][j/3]|=(1<<num);
                col[j]|=(1<<num);
                row[i]|=(1<<num);
            }
        }
    }

    find(0,0);
        
    return 0;
}