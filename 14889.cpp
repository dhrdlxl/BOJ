#include<iostream>
#include<vector>
using namespace std;
int map[20][20];

int min(int a,int b)
{
    return a<b?a:b;
}

int recursive(int index,int count,int bitmask,int N)
{
    int answer=10000;
    if(index==N)return 10000;
    if(count==N/2)
    {
        int a=0,b=0;
        vector<int> teamA,teamB;
        for(int i=0;i<N;i++)
        {
            if((bitmask&(1<<i))==0)
                teamA.push_back(i);
            else
                teamB.push_back(i);
        }
        for(int i=0;i<N/2;i++)
        {
            for(int j=0;j<N/2;j++)
            {
                a+=map[teamA[i]][teamA[j]];
                b+=map[teamB[i]][teamB[j]];
            }
        }
        int sub = a-b;
        if(sub<0)sub*=-1;
        if(answer>sub)answer=sub;
        return answer;
    }
    answer=min(answer,recursive(index+1,count+1,bitmask|(1<<index),N));
    answer=min(answer,recursive(index+1,count,bitmask,N));
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>map[i][j];
        }
    }

    cout<<recursive(0,0,0,N);
    return 0;
}