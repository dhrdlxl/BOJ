#include<iostream>
using namespace std;
int board[4][4];
int N;
int M;
int max(int a,int b)
{
    return a>b? a:b;
}
int go(int index,int bitmask, int sum)
{
    int y=index/M;
    int x=index%M;
    if(index==N*M)
    {
        return sum;
    }
    if((bitmask&(1<<index)))//���� ����� �̹� �� ����� ��
    {
        return go(index+1,bitmask,sum);
    }

    bitmask|=(1<<index);//���� ����� ��
    int maxNum=0;
    
    //���� ��ϸ� ����(1x1)
    maxNum=max(maxNum,go(index+1,bitmask,sum+board[y][x]));

    int m_sum=board[y][x];
    int m_bitmask=bitmask;
    //���� ���簢��
    for(int i=1;(i+x)%M!=0;i++)
    {
        m_sum*=10;
        if((bitmask&(1<<(i+index)))==0)
        {
            m_sum+=board[y][i+x];
            m_bitmask|=(1<<(i+index));
            maxNum=max(maxNum,go(index+i+1,m_bitmask,sum+m_sum));
        }
        else
        {
            break;
        }
    }
    m_sum=board[y][x];
    m_bitmask=bitmask;
    for(int i=1;y+i<N;i++)
    {
        m_sum*=10;
        if((bitmask&(1<<(i*M+index)))==0)
        {
            m_sum+=board[y+i][x];
            m_bitmask|=(1<<(i*M+index));
            maxNum=max(maxNum,go(index+1,m_bitmask,sum+m_sum));
        }
        else
        {
            break;
        }
    }
    return maxNum;
}

int main(){
    scanf("%d%d",&N,&M);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%1d",&board[i][j]);
        }
    }

    printf("%d\n",go(0,0,0));
    return 0;
}