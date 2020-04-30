#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int LIMIT=5;
int max(int a,int b)
{
    return a>b? a:b;
}
vector<int> makeDir(int num)
{
    vector<int> vec(LIMIT);
    for(int k=0;k<LIMIT;k++)
    {
        vec[k]=(3&num);
        num>>=2;//4진법으로 2개씩 본다.(0~3 으로 방향을 나타냄)
    }
    return vec;
}

int go(vector<int> dirs,vector<vector<int>> board)
{
    int answer=0;
    int N=board.size();

    for(int dir : dirs)
    {
        queue<int> q;
        if(dir==0)//left
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(board[i][j]!=0)
                    {
                        q.push(board[i][j]);
                    }
                }
                int index=0;
                int before=0;
                while(!q.empty())
                {
                    if(before==q.front())
                    {
                        board[i][--index]*=2;
                        before=0;
                    }
                    else
                    {
                        board[i][index]=q.front();
                        before=q.front();
                    }
                    index++;
                    q.pop();
                }
                for(;index<N;index++)
                {
                    board[i][index]=0;
                }
            }
        }
        else if(dir==1)//right
        {
            for(int i=0;i<N;i++)
            {
                for(int j=N-1;j>=0;j--)
                {
                    if(board[i][j]!=0)
                    {
                        q.push(board[i][j]);
                    }
                }
                int index=N-1;
                int before=0;
                while(!q.empty())
                {
                    if(before==q.front())
                    {
                        board[i][++index]*=2;
                        before=0;
                    }
                    else
                    {
                        board[i][index]=q.front();
                        before=q.front();
                    }
                    index--;
                    q.pop();
                }
                for(;index>=0;index--)
                {
                    board[i][index]=0;
                }
            }
        }
        else if(dir==2)//up
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(board[j][i]!=0)
                    {
                        q.push(board[j][i]);
                    }
                }
                int index=0;
                int before=0;
                while(!q.empty())
                {
                    if(before==q.front())
                    {
                        board[--index][i]*=2;
                        before=0;
                    }
                    else
                    {
                        board[index][i]=q.front();
                        before=q.front();
                    }
                    index++;
                    q.pop();
                }
                for(;index<N;index++)
                {
                    board[index][i]=0;
                }
            }
        }
        else if(dir==3)//down
        {
            for(int i=0;i<N;i++)
            {
                for(int j=N-1;j>=0;j--)
                {
                    if(board[j][i]!=0)
                    {
                        q.push(board[j][i]);
                    }
                }
                int index=N-1;
                int before=0;
                while(!q.empty())
                {
                    if(before==q.front())
                    {
                        board[++index][i]*=2;
                        before=0;
                    }
                    else
                    {
                        board[index][i]=q.front();
                        before=q.front();
                    }
                    index--;
                    q.pop();
                }
                for(;index>=0;index--)
                {
                    board[index][i]=0;
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]!=0)
            {
                answer=max(answer,board[i][j]);
            }
        }
    }
    return answer;
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

    int answer=0;
    for(int i=0;i<(1<<LIMIT*2);i++)
    {
        vector<int> dir = makeDir(i);
        answer = max(answer,go(dir,board));        
    }
    cout<<answer;
    return 0;
}