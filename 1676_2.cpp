#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,five=0;
    cin>>N;
    for(int i=5;i<N;i*=5)
    {
        five+=N/i;
    }
    cout<<five;
    return 0;
}