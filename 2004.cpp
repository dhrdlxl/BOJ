#include<iostream>
using namespace std;
int fiveCount(int x)
{
    int count=0;
    for(long long int i=5;i<=x;i*=5)
    {
        count+=x/i;
    }
    return count;
}
int twoCount(int x)
{
    int count=0;
    for(long long int i=2;i<=x;i*=2)
    {
        count+=x/i;
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    cout<<min(fiveCount(n)-fiveCount(n-m)-fiveCount(m),
    twoCount(n)-twoCount(n-m)-twoCount(m));
    return 0;
}