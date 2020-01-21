#include<iostream>
using namespace std;
const int chessMapSize = 8;
int main()
{
    char input;
    int answer=0;
    for(int i=1;i<=chessMapSize;i++)
    {
        for(int j=1;j<=chessMapSize;j++)
        {
            cin>>input;
            if((i+j)%2==0 && input=='F')
            {
               answer++;
            }
        }   
    }
    cout<<answer;
    return 0;
}