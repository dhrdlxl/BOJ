#include<iostream>
using namespace std;

//1의 자리가 포함된 수의 개수 + 10의 자리가 포함된 수의 개수 + ....
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int answer=0;
    cin>>N;

    for(int i=1;i<=N;i*=10)
    {
        answer+=N-i+1;
    }

    cout<<answer;
    return 0;
}