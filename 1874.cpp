#include<iostream>
#include<stack>
using namespace std;
int nums[100000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>nums[i];
    
    stack<int> st;
    string answer;
    int i,j;
    
    for(i=1,j=0;j<n;)
    {
        if(i<=nums[j])
        {
            answer+="+\n";
            st.push(i);
            i++;
        }
        if(st.top()==nums[j])
        {
            answer+="-\n";
            st.pop();
            j++;
        }
        else if(nums[j]<st.top()) break;
    }
    if(j!=n)
        cout<<"NO";
    else
        cout<<answer;
    
    return 0;
}