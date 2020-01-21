#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

int location[51];

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1;i<M+1;i++)
    {
        scanf("%d",&location[i]);
    }
    int index=1;
    int move,answer=0;
    while(index<M+1)
    {
        move=min(location[index]-1,N+1-location[index]);
        answer+=move;
        if(move==location[index]-1)move*=-1;

        for(int i=index+1;i<M+1;i++)
        {
            location[i]=location[i]+move-1;
            if(location[i]<1)location[i]+=N;
            else if(location[i]>N)location[i]%=N;
        }
        --N;
        index++;
    }
    printf("%d",answer);
    return 0;
}