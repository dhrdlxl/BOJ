#include<iostream>
using namespace std;

bool col[15];
bool rightup_Diagonal[30];
bool leftup_Diagonal[30];
int solution(int N,int row)
{
    int answer=0;
    if(row==N)
    {
        return 1;
    }
    
    for(int i=0;i<N;i++)
    {
        if(!col[i] && !rightup_Diagonal[row+i] && !leftup_Diagonal[row-i+N-1])
        {
            col[i]=true;
            rightup_Diagonal[row+i]=true;
            leftup_Diagonal[row-i+N-1]=true;
            answer+=solution(N,row+1);
            col[i]=false;
            rightup_Diagonal[row+i]=false;
            leftup_Diagonal[row-i+N-1]=false;
        }
    }
    
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    cout<<solution(N,0);
    return 0;
}