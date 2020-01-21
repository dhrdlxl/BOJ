#include<iostream>
#include<string>
#include<stack>
using namespace std;
string A,B;
stack<char> st;
void sum(bool check){
    int indexA=A.length(),indexB=B.length();
    int numA,numB,carry=0,sum=0,min;
    if(check)min=1;
    else min=0;
    for(--indexA,--indexB; indexA>=min || indexB>=min; indexA--,indexB--)
    {
        if(indexA>=min)
            numA=A[indexA]-'0';
        else numA=0;
        if(indexB>=min)
            numB=B[indexB]-'0';
        else numB=0;
        sum=numA+numB+carry;
        if(sum>=10)carry=1;
        else carry=0;
        st.push(sum%10);
    }
    if(carry==1)st.push(1);
    return;
}

void sub(string C,string D)
{
    int indexC=C.length(),indexD=D.length();
    int numC,numD,carry=0,sub=0;

    for(--indexC,--indexD; indexC>=0 || indexD>=0; indexC--,indexD--)
    {
        if(indexC>=0)
            numC=C[indexC]-'0';
        else numC=0;
        if(indexD>=0)
            numD=D[indexD]-'0';
        else numD=0;
        sub=numC-numD-carry;
        if(sub<0)
        {
            sub+=10;
            carry=1;
        }
        else carry=0;
        st.push(sub);
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin>>A>>B;
    
    if(A[0]=='-'&&B[0]=='-')// - -
    {
        cout<<'-';
        sum(true);
    }
    else if(A[0]!='-'&&B[0]!='-')// + +
    {
        sum(false);
    }
    else // + - / - +
    {

        string C,D;
        
        if(A[0]=='-'){
            for(int i=1;i<A.length();i++)
                C+=A[i];
            D=B;
        }
        else{
            for(int i=1;i<B.length();i++)
                D+=B[i];
            C=A;
        } 
        if(C.length()>D.length())
        {
            if(A[0]=='-')cout<<'-';
            sub(C,D);
        }
        else if(C.length()<D.length())
        {
            if(B[0]=='-')cout<<'-';
            sub(D,C);
        }
        else
        {
            bool same=true;
            for(int i=0;i<C.length();i++)
            {
                if(C[i]>D[i])
                {
                    same=false;
                    if(A[0]=='-')cout<<'-';
                    sub(C,D);
                    break;
                }
                else if(C[i]<D[i])
                {
                    same=false;
                    if(B[0]=='-')cout<<'-';
                    sub(D,C);
                    break;
                }
            }
            if(same)sub(C,D);
        }
    }
    bool zeroCheck=false;
    while(!st.empty())
    {
        if((int)st.top()!=0 || zeroCheck)zeroCheck=true;
        if(zeroCheck || st.size()==1)
            cout<<(int)st.top();
        st.pop();
    }

    return 0;
}