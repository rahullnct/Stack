#include<iostream>
#include<stack>
using namespace std;
void solve(int arr[10],int n,int nge[10])
{
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
       nge[i]= st.empty() ? -1 : st.top();
       st.push(arr[i]);
    }
}
int main()
{
    int arr[10]={4,2,12,5,11,3,5,9,8,10};
    int n=10;
    int nge[10];
    solve(arr,n,nge);
    for(int i=0;i<n;i++)
    {
        cout<<nge[i]<<" ";
    }
}