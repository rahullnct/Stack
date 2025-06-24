#include<iostream>
#include<stack>
using namespace std;
int priority(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch =='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='+' || ch=='-')
    {
        return 1;
    }
    return -1;
}
string solve(string &s,int n)
{
    stack<char>st;
    string ans="";
    int i=0;
    while(i<n)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            // st.push(s[i]);
            ans+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(!st.empty() && (priority(s[i]) <= priority(st.top())))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    i++;
    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string st="(p+q)*(m-n)";
    int n=st.size();
    string ans=solve(st,n);
    cout<<ans;
}