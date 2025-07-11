#include<iostream>
#include<stack>
#include<climits>
using namespace std;
void solve(int arr[2],int n,int pse[2])
{
    int i=0;
    stack<int>st1;
    while(i<n)
    {
        while(!st1.empty() && arr[st1.top()]>arr[i])
        {
            st1.pop();
        }
        pse[i]=st1.empty() ? -1:st1.top();
       st1.push(i);
       i++;
    }
}
void solve2(int arr[2],int n,int nse[2])
{
    int i=n-1;
    stack<int>st1;
    while(i>=0)
    {
        while(!st1.empty() && arr[st1.top()]>arr[i])
        {
            st1.pop();
        }
        nse[i]=st1.empty() ? n:st1.top();
       st1.push(i);
       i--;
    }
}
int maximum_area(int arr[2],int pse[2],int nse[2],int n)
{
    int maxarea=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxarea=max(maxarea,arr[i]*(nse[i]-pse[i]-1));
    }
    return maxarea;
}
int main()
{
    int arr[2]={2,4};
    int n=2;
    int pse[2];
    int nse[2];
    solve(arr,n,pse);
    solve2(arr,n,nse);
    int ans=maximum_area(arr,pse,nse,n);
    cout<<ans<<endl;
}