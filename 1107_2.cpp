//1~1,000,000 을 순회하며 불가능한 수를 제외하고 최솟값을 찾는 방법
#include<iostream>
using namespace std;

int N,M;
bool num[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=0;i<M;i++)
    {
        int x;
        cin>>x;
        num[x]=true;
    }

    int answer=100-N;
    if(answer<0)answer*=-1;

    for(int i=0;i<1000000;i++)
    {
        int x=i;
        int count=0;
        do{
            count++;
            if(num[x%10]==true)
            {
                count=0;
                break;
            }
            x/=10;
        }while(x>0);
        if(count>0)
        {
            int guess=N-i;
            if(guess<0)guess*=-1;
            guess+=count;//버튼 누른 횟수를 더한다.
            if(guess<answer)answer=guess;
        }
    }
    
    cout<<answer;
    return 0;
}