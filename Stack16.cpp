#include<iostream>
#include<stack>
using namespace std;
class stockspan
{
    stack<pair<int,int>>st;
    int ind=-1;
    
    public:
    stockspan()
    {
      ind=-1;
    }
    
    int next(int val)
    {
        ind=ind+1;
        while(!st.empty() && st.top().first <= val)
        {
            st.pop();
        }
        int ans=ind - (st.empty() ? -1 : st.top().second);
        st.push({val,ind});
        return ans;
    }
};
int main()
{
    stockspan sp;
    cout<<sp.next(7)<<" ";
    cout<<sp.next(2)<<" ";
    cout<<sp.next(1)<<" ";
    cout<<sp.next(3)<<" ";
    cout<<sp.next(3)<<" ";
    cout<<sp.next(1)<<" ";
    cout<<sp.next(8)<<" ";
    
}