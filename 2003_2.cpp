#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    int arr[10000];
    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    int answer=0;
    int left=0, right=0;
    int sum=arr[0];
    while(left<N && right<N)
    {
        if(sum<M)
        {
            right++;
            sum+=arr[right];
        }
        else if(sum==M)
        {
            answer++;
            right++;
            sum+=arr[right]-arr[left];
            left++;
        }
        else//sum>M
        {
            sum-=arr[left];
            left++;
        }
    }
    cout<<answer;
    return 0;
}