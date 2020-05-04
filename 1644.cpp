#include<iostream>
#include<vector>
using namespace std;


void eratosthenes(int N,vector<int>& prime)
{
    vector<bool> arr(N+1);
    for(int i=2;i<=N;i++)
    {
        if(arr[i]==false)//家荐老 锭.
        {
            prime.push_back(i);
            for(int j=i+i;j<=N;j+=i)
            {
                arr[j]=true;
            }
        }
    }
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    vector<int> prime;
    eratosthenes(N,prime);

    int left=0,right=0;
    int answer=0;
    int sum=prime.empty()? 0:prime[0];//N捞 1老 锭 贸府.
    int index=prime.size();
    while(left<index && right<index)
    {
        if(sum<N)
        {
            right++;
            if(right<index)
            {
                sum+=prime[right];
            }
        }
        else if(sum==N)
        {
            answer++;
            right++;
            if(right<index)
            {
                sum+=prime[right];
            }
        }
        else if(sum>N)
        {
            sum-=prime[left];
            left++;
        }
    }
    cout<<answer;
    return 0;
}