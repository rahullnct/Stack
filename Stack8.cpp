#include<iostream>
#include<stack>
using namespace std;
string solve(string &s,int n)
{
    stack<string>st;
    int i=0;
    while(i<n)
    {
        if((s[i]>='a' && s[i]<'z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
        {
            st.push(string(1,s[i]));
        }
        else{
            string s1=st.top(); st.pop();
            string s2=st.top(); st.pop();
            string cons=s[i]+s2+s1;
            st.push(cons);
        }
        i++;
    }
    return st.top();
}
int main()
{
    string s="AB+CD-*";
    int n=s.size();
    string ans=solve(s,n);
    cout<<ans;
}