#include<iostream>
using namespace std;

int main(){
    int N,M;
    int board[4][4];
    scanf("%d%d",&N,&M);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%1d",&board[i][j]);
        }
    }

    int answer=0;
    for(int i=0;i<(1<<(N*M));i++)// 0 ���� 1 ����
    {
        int sum=0;
        //���η� ������ ���簢��
        for(int y=0;y<N;y++)
        {
            int temp=0;
            for(int x=0;x<M;x++)
            {
                if((i&(1<<(y*M+x)))==0)
                {
                    temp=temp*10+board[y][x];
                }
                else
                {
                    sum+=temp;
                    temp=0;
                }
            }
            sum+=temp;
        }

        //���η� ������ ���簢��
        for(int x=0;x<M;x++)
        {
            int temp=0;
            for(int y=0;y<N;y++)
            {
                if((i&(1<<(y*M+x)))!=0)
                {
                    temp=temp*10+board[y][x];
                }
                else
                {
                    sum+=temp;
                    temp=0;
                }
            }
            sum+=temp;
        }
        if(answer<sum)answer=sum;
    }

    printf("%d",answer);

    return 0;
}