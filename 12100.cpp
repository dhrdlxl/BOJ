#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int max(int a,int b)
{
    return a>b? a:b;
}
int go(int count,vector<vector<int>> boards,int dir)
{
    int ans=0;
    int n=boards.size();
    if(count==5)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(boards[i][j]!=0)
                    ans=max(ans,boards[i][j]);
            }
        }
        return ans;
    }

    vector<vector<int>> board = boards;
    //4πÊ«‚
    // <-
    if(dir!=0)
    {
        int m_dir=-1;
        for(int i=0;i<n;i++)
        {
            queue<int> q;
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!=0)
                    q.push(board[i][j]);
            }
            int index=0;
            int before=-1;
            int before2=-1;
            while(!q.empty())
            {
                int num =q.front();
                if(before2==num)
                {
                    m_dir=0;
                }
                if(before==num)
                {
                    index--;
                    board[i][index]*=2;
                    before=-100;
                    before2=board[i][index];
                }
                else
                {
                    board[i][index]=num;
                    before=num;
                    before2=-100;
                }
                q.pop();
                index++;
            }
            for(int j=index;j<n;j++)
            {
                board[i][j]=0;
            }
        }
        ans=max(ans,go(count+1,board,m_dir));
    }
    

    // ->
    if(dir!=1)
    {
        board = boards;
        int m_dir=-1;
        for(int i=0;i<n;i++)
        {
            queue<int> q;
            for(int j=n-1;j>=0;j--)
            {
                if(board[i][j]!=0)
                    q.push(board[i][j]);
            }
            int index=n-1;
            int before=-1;
            int before2=-1;
            while(!q.empty())
            {
                int num =q.front();
                if(before2==num)
                {
                    m_dir=1;
                }
                if(before==num)
                {
                    index++;
                    board[i][index]*=2;
                    before=-100;
                    before2=board[i][index];
                }
                else
                {
                    board[i][index]=num;
                    before=num;
                    before2=-1;
                }
                q.pop();
                index--;
            }
            for(int j=index;j>=0;j--)
            {
                board[i][j]=0;
            }
        }
        ans=max(ans,go(count+1,board,m_dir));
    }
    
    // ^
    // |
    if(dir!=2)
    {
        board = boards;
        int m_dir=-1;
        for(int i=0;i<n;i++)
        {
            queue<int> q;
            for(int j=0;j<n;j++)
            {
                if(board[j][i]!=0)
                    q.push(board[j][i]);
            }
            int index=0;
            int before=-1;
            int before2=-1;
            while(!q.empty())
            {
                int num =q.front();
                if(before2==num)
                {
                    m_dir=2;
                }
                if(before==num)
                {
                    index--;
                    board[index][i]*=2;
                    before=-100;
                    before2=board[index][i];
                }
                else
                {
                    board[index][i]=num;
                    before=num;
                    before2=-1;
                }
                q.pop();
                index++;
            }
            for(int j=index;j<n;j++)
            {
                board[j][i]=0;
            }
        }
        ans=max(ans,go(count+1,board,m_dir));
    }


    // |
    // V
    if(dir!=3)
    {
        board = boards;
        int m_dir=-1;
        for(int i=0;i<n;i++)
        {
            queue<int> q;
            for(int j=n-1;j>=0;j--)
            {
                if(board[j][i]!=0)
                    q.push(board[j][i]);
            }
            int index=n-1;
            int before=-1;
            int before2=-1;
            while(!q.empty())
            {
                int num =q.front();
                if(before2==num)
                {
                    m_dir=3;
                }
                if(before==num)
                {
                    index++;
                    board[index][i]*=2;
                    before=-100;
                    before2=board[index][i];
                }
                else
                {
                    board[index][i]=num;
                    before=num;
                    before2=-1;
                }
                q.pop();
                index--;
            }
            for(int j=index;j>=0;j--)
            {
                board[j][i]=0;
            }
        }
        ans=max(ans,go(count+1,board,m_dir));
    }
    

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<vector<int>> board(N,vector<int>(N));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }

    cout<<go(0,board,-1);
    return 0;
}