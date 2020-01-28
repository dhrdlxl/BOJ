#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    int answer=1;//0! = 1 
    while(N>0)
        answer*=N--;
    cout<<answer;
    return 0;
}