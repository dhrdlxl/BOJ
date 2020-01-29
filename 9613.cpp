#include<iostream>
using namespace std;
int gcd(int a,int b)
{ 
    return a%b? gcd(b,a%b) : b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t,n,array[100];
    
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long int answer=0;
        for(int i=0;i<n;i++)
        {
            cin>>array[i];
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                answer+=gcd(array[i],array[j]);
            }
        }
        cout<<answer<<'\n';
    }
    return 0;
}