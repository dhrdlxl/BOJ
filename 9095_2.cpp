#include<iostream>
using namespace std;

int goal(int sum,int target)
{
    if(sum>target)return 0;
    else if(sum==target)
        return 1;
    int answer=0;
    for(int i=1;i<=3;i++)
    {
        answer+=goal(sum+i,target);
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<goal(0,n)<<'\n';
    }
    
    return 0;
}