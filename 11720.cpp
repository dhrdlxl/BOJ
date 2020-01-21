#include<iostream>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    int N;
    char num;
    int answer=0;
    cin>>N;
    while(N-->0)
    {
        cin>>num;
        answer+=num-'0';
    }
    cout<<answer;
    return 0;
}