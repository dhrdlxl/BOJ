#include<iostream>
#include<string>
using namespace std;
bool checker(string brackets)
{
    int sum=0;
    for(char ch:brackets)
    {
        if(ch=='(')sum++;
        else if(ch==')')sum--;
        if(sum<0) return false;
    }
    if(sum==0) return true;
    else return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    string s;
    while(T--)
    {
        cin>>s;
        if(checker(s))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    
    return 0;
}