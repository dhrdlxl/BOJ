#include<iostream>
#include<cstring>
using namespace std;

int chess[14][14];
int recursive(int N,int count,int y,int x)
{
    if(N==count)
        return 1;

    int ans=0;
    chess[y][x]+=1;
    //mask 갱신
    //1.행
    for(int a=x+1;a<N;a++)
    {
        chess[y][a]++;
    }
    //2.아래
    for(int a=y+1;a<N;a++)
    {
        chess[a][x]++;
    }
    //3.오른쪽 아래
    for(int a=x+1,b=y+1;a<N && b<N;a++,b++)
    {
        chess[b][a]++;
    }
    //4.왼쪽 아래
    for(int a=x-1,b=y+1;a>=0 && b<N;a--,b++)
    {
        chess[b][a]++;
    }

    //다음 퀸 놓을 위치 선정

    if(y+1<N)
    {
        for(int j=0;j<N;j++)
        {
            if(chess[y+1][j]==0)
            {
                ans+=recursive(N,count+1,y+1,j);
            }
        }
    }
    //1.행
    for(int a=x+1;a<N;a++)
    {
        chess[y][a]--;
    }
    //2.아래
    for(int a=y+1;a<N;a++)
    {
        chess[a][x]--;
    }
    //3.오른쪽 아래
    for(int a=x+1,b=y+1;a<N && b<N;a++,b++)
    {
        chess[b][a]--;
    }
    //4.왼쪽 아래
    for(int a=x-1,b=y+1;a>=0 && b<N;a--,b++)
    {
        chess[b][a]--;
    }
    chess[y][x]-=1;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    int answer=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            memset(chess,0,sizeof(chess));
            answer+=recursive(N,1,i,j);
        }
    }
    cout<<answer;
    return 0;
}