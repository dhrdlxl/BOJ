#include<iostream>
using namespace std;

void consulting(int p[][2],int n,int day,int severance_pay,int& answer)
{
    if(day==n)
    {
        if(answer<severance_pay) 
            answer = severance_pay;
        return;
    }
    if(day>n)return;
    
    consulting(p,n,day+p[day][0],severance_pay+p[day][1],answer);
    consulting(p,n,day+1,severance_pay,answer);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int pay[15][2];
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<2;j++)
            cin>>pay[i][j];
    }
    int answer=0;
    consulting(pay,N,0,0,answer);
    cout<<answer;
    return 0;
}