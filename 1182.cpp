#include<iostream>
#include<vector>
using namespace std;

void find(vector<int>& vec,int index,int sum,int target,int& answer)
{
    if(index==vec.size())
    {
        if(sum==target)answer++;
        return;
    }

    find(vec,index+1,sum,target,answer);
    find(vec,index+1,sum+vec[index],target,answer);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,s;
    cin>>n>>s;
    vector<int> array(n);
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int answer=0;
    if(s==0)answer--;
    find(array,0,0,s,answer);
    cout<<answer;
    return 0;
}