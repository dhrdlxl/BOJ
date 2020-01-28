#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,five=0;
    cin>>N;
    while(N>0)
    {
        int M=N;
        while(M%5==0&&M!=0)
        {
            five++;
            M/=5;
        }
        N--;
    }
    cout<<five;
    return 0;
}