#include<iostream>
#include<deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;

    int num;
    int sum=0;
    int answer=0;
    deque<int> dq;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        dq.push_back(num);
        sum+=num;
        while(sum>M)
        {
            sum-=dq.front();
            dq.pop_front();
        }
        if(sum==M) answer++;
    }
    cout<<answer;
    return 0;
}