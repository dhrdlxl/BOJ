#include<iostream>
using namespace std;

bool prime(int a){
    if(a<2) return false;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, answer=0, num;
    cin>>N;

    while(N--)
    {
        cin>>num;
        if(prime(num))
            answer++;
    }
    cout<<answer;
    return 0;
}