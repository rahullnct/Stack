#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string solve(string &s,int n,int k)
{
    stack<char>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && k>0 && st.top()-'0'>s[i]-'0')
        {
            st.pop();
            k--;
        }
      st.push(s[i]);
    }
    while(k>0)
    {
        st.pop();
        k--;
    }
    if(st.empty())
    {
        return "0";
    }
    string res="";
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    while(res.size()!=0 && res.back()==0)
    {
        res.pop_back();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    string s="1432219";
    int n=s.size();
    string ans=solve(s,n,3);
    cout<<ans;
}