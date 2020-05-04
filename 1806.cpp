#include<iostream>
using namespace std;

int min(int a,int b)
{
    return a<b? a:b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,S;
    cin>>N>>S;

    int arr[100001];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    int answer=100001;
    int left=0, right=0;
    int sum=arr[0];

    while(left<N && right<N)
    {
        if(sum<S)
        {
            right++;
            if(right<N)
            {
                sum+=arr[right];
            }
        }
        else if(sum>=S)
        {
            answer=min(answer,right-left+1);
            sum-=arr[left];
            left++;
        }
    }

    if(answer==100001)//불가능한 경우
        answer=0;
    cout<<answer;
    return 0;
}