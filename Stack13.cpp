#include<iostream>
#include<stack>
using namespace std;
void solve(int arr[5],int pse[5],int n)
{
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        pse[i]= st.empty() ? -1 : st.top();
       st.push(i);
    }
}
void solve2(int arr[5],int nse[5],int n)
{
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        nse[i]= st.empty() ? n : st.top();
       st.push(i);
    }
}
int subarraysums(int arr[5],int pse[5],int nse[5],int n)
{
    int total=0;
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        total+=(long long)(left*right*arr[i]);
    }
    return total;
}
int main()
{
    int arr[5]={11,81,94,43,3};
    int n=5;
    int pse[5];
    int nse[5];
    solve(arr,pse,n);
    solve2(arr,nse,n);
    int ans=subarraysums(arr,pse,nse,n);
    cout<<ans<<endl;
}