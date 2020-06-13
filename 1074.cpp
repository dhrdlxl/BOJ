#include <iostream>

using namespace std;

int recursive(const int &N, int r, int c)
{
    if(N == 1)
    {
        return r*2+c;
    }
    int answer = 0;
    int size=1;
    for(int index=0; index < N ; index++)
    {
        size*=2;
    }
    
    int row = 0;
    int col = 0;
    
    if(r >= size/2)
    {
        row = 2;
        r %= (size/2);
    }
    if(c >= size/2)
    {
        col = 1;
        c %= (size/2);
    }
    answer = (size / 2) *(size / 2) * (row + col);
  
    return answer += recursive(N - 1, r, c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,r,c;
    cin>>N>>r>>c;
    
    cout << recursive(N, r, c);
    
    return 0;
}