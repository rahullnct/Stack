#include<iostream>
#include<stack>
using namespace std;
bool solve(string s)
{
   stack<char>st;
   for(int i=0;i<s.size();i++)
   {
     if(s[i]=='(' || s[i]=='{' || s[i]=='[')
     {
        st.push(s[i]);
     }
     else{
        if(st.empty())
        {
            return false;
        }
        else{
            char ch=st.top(); st.pop();
            if((s[i]==')' && ch!='(') || (s[i]=='}' && ch!='{') || (s[i]==']' && ch!='['))
            {
                return false;
            }  
        }
     }
   }
   return st.empty();
}
int main()
{
    string s="([{}])";
    bool ans=solve(s);
    cout<<ans;
} 