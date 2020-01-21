#include<iostream>
#include<algorithm>
using namespace std;
int Schedule[17][2];
int Answer[17];
int main(){
    int N;
    cin.sync_with_stdio(false);
    cin>>N;
    
    for(int j=1;j<N+1;j++)
    {
        for(int i=0;i<2;i++)
        {
            cin>>Schedule[j][i];
        }
    }
    
    
    int last_day=0;
    for(int i=1;i<N+1;i++)
    {
        last_day = Schedule[i][0]+i-1;
        if(last_day<N+1)
        {
            Answer[last_day] = max(Answer[last_day], Schedule[i][1]+Answer[i-1]);
        }
        Answer[i+1] = max(Answer[i],Answer[i+1]);
    }

    cout<<Answer[N];

    return 0;
}