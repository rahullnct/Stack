#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int priority(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='+' || ch=='-') 
    {
        return 1;
    }
  return -1;
}
string solve(string s, int n)
{
    stack<char>st;
    int i=0;
    string ans="";
    while(i<n)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            ans+=s[i];
        }
        else if(s[i]==')')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            while(!st.empty() && st.top()!=')')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i]=='^')
            {
                while(!st.empty() && priority(s[i])< priority(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && (priority(s[i])< priority(st.top())))
                {
                    ans+=st.top();
                    st.pop();
                }
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
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string s="(a-b/c)*(a/k-l)";
    int n=s.size();
    reverse(s.begin(),s.end());
    string ans=solve(s,n);
    cout<<ans;
}