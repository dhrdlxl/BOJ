#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    return a%b ? gcd(b,a%b) : b;
}

int lcm(int a,int b,int gcd)
{
    return a*b/gcd;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,answer_gcd;
    
    cin>>a>>b;
    
    answer_gcd=gcd(a,b);
    cout<<answer_gcd<<'\n'<<lcm(a,b,answer_gcd);
    
    return 0;
}