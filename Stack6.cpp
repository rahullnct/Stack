#include<iostream>
#include<stack>
using namespace std;
string solve(string &s,int n)
{
    stack<string>st;
    int i=0;
    while(i<n)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            st.push(string(1,s[i]));
        }
        else{
            string ch1=st.top(); st.pop();
            string ch2=st.top(); st.pop();
            string cons='('+ch2+s[i]+ch1+')';
            st.push(cons);
        }
        i++;
    }
return st.top();

}
int main()
{
    string s="abc++";
    int n=s.size();
    string ans=solve(s,n);
    cout<<ans<<endl;
}