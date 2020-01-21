#include<iostream>
using namespace std;
int map[101][101];
bool mask[101][101];
int main()
{
    int N,L;
    scanf("%d%d",&N,&L);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&map[i][j]);
            mask[i][j]=false;
        }
    }
    
    int answer=0;
    int pre_block,k;
    bool check;
    for(int i=0;i<N;i++)
    {
        pre_block=map[i][0];
        check=true;
        for(int j=0;j<N;j++)
        {
            if(pre_block-map[i][j]>1 || pre_block-map[i][j]<-1)
            {
                check=false;
                break;
            }
            else if(pre_block-map[i][j]==1)
            {
                k=L;
                while(--k>=0)
                {
                    if(j+k>=N)break;
                    else if(map[i][j+k]!=pre_block-1 || mask[i][j+k])
                    {
                        k=L;
                        break;
                    }
                    else{
                        mask[i][j+k]=true;
                    }
                }
                if(k>0)
                {
                    check=false;
                    break;
                }
            }
            else if(pre_block-map[i][j]==-1)
            {
                k=L+1;
                while(--k>0)
                {
                    if(j-k<0)break;
                    else if(map[i][j-k]!=map[i][j]-1 || mask[i][j-k])
                    {
                        k=L;
                        break;
                    }
                    else{
                        mask[i][j-k]=true;
                    }
                }
                if(k>0)
                {
                    check=false;
                    break;
                }
            }
            pre_block=map[i][j];   
        }
        if(check)answer++;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            mask[i][j]=false;
        }
    }
    
    for(int j=0;j<N;j++)
    {
        pre_block=map[0][j];
        check=true;
        for(int i=0;i<N;i++)
        {
            if(pre_block-map[i][j]>1 || pre_block-map[i][j]<-1)
            {
                check=false;
                break;
            }
            else if(pre_block-map[i][j]==1)
            {
                k=L;
                while(--k>=0)
                {
                    if(i+k>=N)break;
                    else if(map[i+k][j]!=pre_block-1 || mask[i+k][j])
                    {
                        k=L;
                        break;
                    }
                    else{
                        mask[i+k][j]=true;
                    }
                }
                if(k>0)
                {
                    check=false;
                    break;
                }
            }
            else if(pre_block-map[i][j]==-1)
            {
                k=L+1;
                while(--k>0)
                {
                    if(i-k<0)break;
                    else if(map[i-k][j]!=map[i][j]-1 || mask[i-k][j])
                    {
                        k=L;
                        break;
                    }
                    else{
                        mask[i-k][j]=true;
                    }
                }
                if(k>0)
                {
                    check=false;
                    break;
                }
            }   
            pre_block=map[i][j];
        }
        if(check)answer++;
    }
    printf("%d\n",answer);
    return 0;
}